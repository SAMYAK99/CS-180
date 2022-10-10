// To parse this JSON data, do
//
//     final gamesModel = gamesModelFromJson(jsonString);

import 'dart:convert';

List<GamesListModel> gamesListModelFromJson(String str) => List<GamesListModel>.from(json.decode(str).map((x) => GamesListModel.fromJson(x)));

String gamesListModelToJson(List<GamesListModel> data) => json.encode(List<dynamic>.from(data.map((x) => x.toJson())));

class GamesListModel {
  GamesListModel({
    required this.id,
    required this.title,
    required this.thumbnail,
    required this.shortDescription,
    required this.gameUrl,
    required this.genre,
    required this.platform,
    required this.publisher,
    required this.developer,
    required this.releaseDate,
    required this.freetogameProfileUrl,
  });

  int id;
  String title;
  String thumbnail;
  String shortDescription;
  String gameUrl;
  String genre;
  String platform;
  String publisher;
  String developer;
  String releaseDate;
  String freetogameProfileUrl;

  factory GamesListModel.fromJson(Map<String, dynamic> json) => GamesListModel(
    id: json["id"],
    title: json["title"],
    thumbnail: json["thumbnail"],
    shortDescription: json["short_description"],
    gameUrl: json["game_url"],
    genre: json["genre"],
    platform: json["platform"],
    publisher: json["publisher"],
    developer: json["developer"],
    releaseDate: json["release_date"],
    freetogameProfileUrl: json["freetogame_profile_url"],
  );

  Map<String, dynamic> toJson() => {
    "id": id,
    "title": title,
    "thumbnail": thumbnail,
    "short_description": shortDescription,
    "game_url": gameUrl,
    "genre": genre,
    "platform": platform,
    "publisher": publisher,
    "developer": developer,
    "release_date": releaseDate,
    "freetogame_profile_url": freetogameProfileUrl,
  };
}
