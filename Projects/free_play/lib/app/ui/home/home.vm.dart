import 'package:flutter/material.dart';
import 'package:flutter_twitch_player/flutter_twitch_player.dart';
import 'package:free_play/app/ui/home/data/model/games_list_model.dart';
import 'package:free_play/app/ui/home/data/model/stream_model.dart';
import 'package:free_play/app/ui/home/data/model/stream_response_model.dart';
import 'package:free_play/app/ui/home/data/repo/home_content_repo.dart';
import 'package:free_play/core/data/model/setmodel.dart';
import 'package:free_play/core/data/model/setmodellist.dart';
import 'package:pmvvm/pmvvm.dart';

class HomeVm extends ViewModel with HomeContentRepo {
  SetModelList<GamesListModel> listGamesPopular = SetModelList<GamesListModel>();
  SetModelList<GamesListModel> listGames = SetModelList<GamesListModel>();
  List<String> topFiveImage = [];
  final List<GamesListModel> searchResult = [];
  final List<GamesListModel> _gameDetails = [];
  TextEditingController controller = TextEditingController();

  @override
  void init() {
    super.init();
    getGamesList();
    getGamesListPopular();
  }

  @override
  void onResume() {
    getGamesList();
    getGamesListPopular();
  }

  Future<void> getGamesList() async {
    listGames.loading = true;
    notifyListeners();
    listGames.items = {};

    try {
      final res = await repoGetListGame('release-date');

      if (res != null && res != 0) {
        listGames.items?.addAll(res);
        _gameDetails.addAll(res.toList());
      }
    } catch (e) {
      listGames.error = e.toString();
      debugPrint(e.toString());
    }

    listGames.loading = false;
    notifyListeners();
  }

  Future<void> getGamesListPopular() async {
    listGamesPopular.loading = true;
    notifyListeners();
    listGamesPopular.items = {};

    try {
      final res = await repoGetListGame('popular');

      if (res != null && res != 0) {
        listGamesPopular.items?.addAll(res);
        getTopFiveImage(listGamesPopular.items!);
      }
    } catch (e) {
      listGamesPopular.error = e.toString();
      debugPrint(e.toString());
    }

    listGamesPopular.loading = false;
    notifyListeners();
  }

  getTopFiveImage(Set<GamesListModel> data) {
    for (var i = 0; i < 5; i++) {
      topFiveImage.add(data.elementAt(i).thumbnail);
    }
    notifyListeners();
  }

  onSearchTextChanged(String text) async {
    searchResult.clear();
    if (text.isEmpty) {
      notifyListeners();
      return;
    }

    for (var gamesListModel in listGames.items!) {
      if (gamesListModel.title.contains(text) ) {
        searchResult.add(gamesListModel);
      }
    }
    notifyListeners();
  }
}
