import 'package:free_play/app/ui/home/data/model/game_detail_model.dart';
import 'package:free_play/core/data/constant/app_constant.dart';
import 'package:free_play/core/data/network/app_network.dart';

class GameDetailNetwork {
  Future<GameDetailModel> apiGetProductDetail({required int id}) async {
    try {
      final res = await AppNetworkClient.get(
          url: AppConstant.baseUrl,
          path: 'game',
          data: {
            'id': id,
          });
      return GameDetailModel.fromJson(res.data);
    } catch (e) {
      rethrow;
    }
  }
}
