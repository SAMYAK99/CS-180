import 'package:free_play/app/ui/home/data/model/games_list_model.dart';
import 'package:free_play/app/ui/home/data/model/stream_model.dart';
import 'package:free_play/app/ui/home/data/model/stream_response_model.dart';
import 'package:free_play/app/ui/home/data/network/home_content_network.dart';

class HomeContentRepo {
  final _myNetwork = HomeContentNetwork();

  Future<List<GamesListModel>> repoGetListGame(String sort) async {
    try {
      return await _myNetwork.apiGetListGames(sort);
    } catch (e) {
      rethrow;
    }
  }

  Future<StreamResponseModel> repoGetListStream() async {
    try {
      return await _myNetwork.apiGetStreamList();
    } catch (e) {
      rethrow;
    }
  }

}
