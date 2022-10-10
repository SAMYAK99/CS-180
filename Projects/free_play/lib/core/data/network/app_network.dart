import 'package:flutter/material.dart';
import 'package:dio/dio.dart';
import 'package:free_play/core/data/constant/app_constant.dart';

class AppNetworkClient {
  static Dio _dio = Dio()..options.connectTimeout = 10000;

  static String? baseurl = AppConstant.baseUrl;

  AppNetworkClient._();

  static final AppNetworkClient _instance = AppNetworkClient._();

  factory AppNetworkClient() {
    return _instance;
  }

  static Future<Response> get({
    Map<String, dynamic>? data,
    required String url,
    Map<String, dynamic>? customHeader,
    required String path,
  }) async {
    try {
      final res = await _dio.get(url + path,
          queryParameters: data, options: Options(headers : customHeader));

      debugPrint("CALLING GET " + res.requestOptions.path);
      debugPrint("Query GET " + res.requestOptions.queryParameters.toString());

      // debugPrint("Data Response " + res.data.toString());

      return res;
    } on DioError catch (e) {
      _errorCatch(e);
      try {
        throw "[500] Server Error, try again later";
      } catch (e) {
        throw e.toString();
      }
    } catch (e) {
      throw "Something Went Wrong";
    }
  }

  static Future<Response> post({
    Map<String, dynamic>? data,
    String? url,
    Map<String, dynamic>? customHeader,
    required String path,
    FormData? form,
    // jsonMap for sending raw json to server
    Map<String, dynamic>? jsonMap,
  }) async {
    try {
      final res = await _dio.post((url ?? baseurl)! + path,
          data: form ?? jsonMap ?? FormData.fromMap(data!));

      debugPrint("CALLING POST " + res.requestOptions.path);
      // debugPrint("Response Data " + res.data.toString());

      return res;
    } on DioError catch (e) {
      _errorCatch(e);
      try {
        throw "[${e.response!.statusCode}] Server Error, try again later";
      } catch (e) {
        rethrow;
      }
    } catch (e) {
      throw "Something Went Wrong";
    }
  }

  static void _errorCatch(DioError e) {
    if (e.response != null) {
      debugPrint("Error CALLING " + e.requestOptions.path);

      debugPrint("Error Status Code " + e.response!.statusCode.toString());
      debugPrint("Error Response " + e.response!.data.toString());
    } else {
      // Something happened in setting up or sending the requestOptions that triggered an Error
      debugPrint("CALLING " + e.requestOptions.toString());
      print(e.message);
    }
  }
}
