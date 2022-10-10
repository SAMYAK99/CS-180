// To parse this JSON data, do
//
//     final streamResponseModel = streamResponseModelFromJson(jsonString);

import 'dart:convert';

import 'package:free_play/app/ui/home/data/model/stream_model.dart';

StreamResponseModel streamResponseModelFromJson(String str) => StreamResponseModel.fromJson(json.decode(str));

String streamResponseModelToJson(StreamResponseModel data) => json.encode(data.toJson());

class StreamResponseModel {
  StreamResponseModel({
    required this.data,
    required this.pagination,
  });

  List<StreamModel> data;
  Pagination pagination;

  factory StreamResponseModel.fromJson(Map<String, dynamic> json) => StreamResponseModel(
    data: List<StreamModel>.from(json["data"].map((x) => StreamModel.fromJson(x))),
    pagination: Pagination.fromJson(json["pagination"]),
  );

  Map<String, dynamic> toJson() => {
    "data": List<dynamic>.from(data.map((x) => x.toJson())),
    "pagination": pagination.toJson(),
  };
}

enum GameName { MINECRAFT }

final gameNameValues = EnumValues({
  "Minecraft": GameName.MINECRAFT
});

enum Type { LIVE }

final typeValues = EnumValues({
  "live": Type.LIVE
});

class Pagination {
  Pagination({
    required this.cursor,
  });

  String cursor;

  factory Pagination.fromJson(Map<String, dynamic> json) => Pagination(
    cursor: json["cursor"],
  );

  Map<String, dynamic> toJson() => {
    "cursor": cursor,
  };
}

class EnumValues<T> {
  Map<String, T> map;
  late Map<T, String> reverseMap;

  EnumValues(this.map);

  Map<T, String> get reverse {
    if (reverseMap == null) {
      reverseMap = map.map((k, v) => new MapEntry(v, k));
    }
    return reverseMap;
  }
}
