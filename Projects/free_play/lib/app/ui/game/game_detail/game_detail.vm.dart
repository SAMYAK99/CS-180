import 'package:flutter/material.dart';
import 'package:flutter_twitch_player/flutter_twitch_player.dart';
import 'package:free_play/app/ui/game/game_detail/data/repo/game_detail.repo.dart';
import 'package:free_play/app/ui/game/game_detail/game_detail.props.dart';
import 'package:free_play/app/ui/home/data/model/game_detail_model.dart';
import 'package:free_play/app/ui/home/home.view.dart';
import 'package:free_play/core/data/model/setmodel.dart';
import 'package:free_play/core/data/model/setmodellist.dart';
import 'package:pmvvm/pmvvm.dart';

class GameDetailVm extends ViewModel with GameDetailRepo {
  late GameDetailProps props;
  SetModel<GameDetailModel>? detailGame = SetModel<GameDetailModel>();

  @override
  void init() {
    super.init();
    props = context.fetch<GameDetailProps>();

    getGameDetail();
  }

  Future<void> getGameDetail() async {
    detailGame?.loading = true;
    notifyListeners();
    detailGame?.item = null;

    try {
      final res = await repoGetGameDetail(id: props.id);

      print(res.toJson());
      detailGame?.item = res;
      notifyListeners();
    } catch (e) {
      detailGame?.error = e.toString();
      debugPrint(e.toString());
    }

    detailGame?.loading = false;
    notifyListeners();
  }
}