class StreamModel {
  StreamModel({
    required this.id,
    required this.userId,
    required this.userLogin,
    required this.userName,
    required this.gameId,
    required this.gameName,
    required this.type,
    required this.title,
    required this.viewerCount,
    required this.startedAt,
    required this.language,
    required this.thumbnailUrl,
    required this.tagIds,
    required this.isMature,
  });

  String id;
  String userId;
  String userLogin;
  String userName;
  String gameId;
  String gameName;
  String type;
  String title;
  int viewerCount;
  String startedAt;
  String language;
  String thumbnailUrl;
  List<String> tagIds;
  bool isMature;

  factory StreamModel.fromJson(Map<String, dynamic> json) => StreamModel(
    id: json["id"],
    userId: json["user_id"],
    userLogin: json["user_login"],
    userName: json["user_name"],
    gameId: json["game_id"],
    gameName: json["game_name"],
    type: json["type"],
    title: json["title"],
    viewerCount: json["viewer_count"],
    startedAt: json["started_at"],
    language: json["language"],
    thumbnailUrl: json["thumbnail_url"],
    tagIds: json['tag_ids'].cast<String>(),
    isMature: json["is_mature"],
  );

  Map<String, dynamic> toJson() => {
    "id": id,
    "user_id": userId,
    "user_login": userLogin,
    "user_name": userName,
    "game_id": gameId,
    "game_name": gameName,
    "type": type,
    "title": title,
    "viewer_count": viewerCount,
    "started_at": startedAt,
    "language": language,
    "thumbnail_url": thumbnailUrl,
    "tag_ids": tagIds,
    "is_mature": isMature,
  };
}