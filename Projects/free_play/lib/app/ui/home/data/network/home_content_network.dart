import 'package:free_play/app/ui/home/data/model/games_list_model.dart';
import 'package:free_play/app/ui/home/data/model/stream_model.dart';
import 'package:free_play/app/ui/home/data/model/stream_response_model.dart';
import 'package:free_play/core/data/constant/app_constant.dart';
import 'package:free_play/core/data/network/app_network.dart';

class HomeContentNetwork {
  Future<List<GamesListModel>> apiGetListGames(String sort) async {
    try {
      final res = await AppNetworkClient.get(
          url: AppConstant.baseUrl, path: 'games', data: {'sort-by': sort});
      return (res.data as List).map((x) => GamesListModel.fromJson(x)).toList();
    } catch (e) {
      rethrow;
    }
  }

  Future<StreamResponseModel> apiGetStreamList() async {
    try {
      final res = await AppNetworkClient.get(
          url: AppConstant.twitchApiUrl, path: 'streams');
      return StreamResponseModel.fromJson(res.data);
    } catch (e) {
      rethrow;
    }
  }
}
