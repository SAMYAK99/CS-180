import 'package:free_play/app/ui/game/game_detail/data/network/game_detail.network.dart';
import 'package:free_play/app/ui/home/data/model/game_detail_model.dart';
import 'package:free_play/app/ui/home/data/model/games_list_model.dart';
import 'package:free_play/app/ui/home/data/network/home_content_network.dart';

class GameDetailRepo {
  final _myNetwork = GameDetailNetwork();

  Future<GameDetailModel> repoGetGameDetail(
      {required int id}) async {
    try {
      return await _myNetwork.apiGetProductDetail(id: id);
    } catch (e) {
      rethrow;
    }
  }
}
