import 'dart:ui';

import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';
import 'package:flutter_twitch_player/flutter_twitch_player.dart';
import 'package:free_play/app/ui/game/game_detail/game_detail.vm.dart';
import 'package:free_play/app/ui/home/data/model/game_detail_model.dart';
import 'package:free_play/core/data/model/setmodel.dart';
import 'package:free_play/core/style/app_color.dart';
import 'package:free_play/core/style/app_values.dart';
import 'package:free_play/core/widgets/image_url.dart';
import 'package:pmvvm/pmvvm.dart';

import 'game_detail.props.dart';

class GameDetailScreen extends StatelessWidget {
  GameDetailScreen({
    Key? key,
    required int id,
  })  : props = GameDetailProps(id: id),
        super(key: key);
  final GameDetailProps props;

  @override
  Widget build(BuildContext context) {
    return Provider.value(
        value: props,
        child: MVVM<GameDetailVm>(
            view: () => _GameDetailScreen(), viewModel: GameDetailVm()));
  }
}

class _GameDetailScreen extends StatelessView<GameDetailVm> {
  int _crossAxisCount = 2;
  double _aspectRatio = 1.5;

  @override
  Widget render(BuildContext context, GameDetailVm viewModel) {
    return Scaffold(
      backgroundColor: Colors.white,
      body: NestedScrollView(
        headerSliverBuilder: (BuildContext context, bool innerBoxIsScrolled) {
          return [
            SliverAppBar(
              backgroundColor: const Color(0xFF313640),
              expandedHeight: 250.0,
              leading: IconButton(
                onPressed: () {
                  Navigator.of(context).pop();
                },
                icon: const Icon(
                  Icons.keyboard_arrow_left_outlined,
                  color: Colors.grey,
                ),
              ),
              flexibleSpace: Stack(
                children: [
                  Positioned.fill(
                      child: ImageUrl(
                          fit: BoxFit.cover,
                          fileName:
                              viewModel.detailGame?.item?.thumbnail ?? '')),
                  Positioned(
                    bottom: -1,
                    left: 0,
                    right: 0,
                    child: Container(
                      height: 30,
                      decoration: const BoxDecoration(
                        color: Color(0xFF313640),
                        borderRadius: BorderRadius.vertical(
                          top: Radius.circular(AppValues.size_16),
                        ),
                      ),
                    ),
                  ),
                ],
              ),
              actions: [
                Container(
                  width: 75,
                  height: 20,
                  margin: const EdgeInsets.only(
                      right: AppValues.size_8,
                      bottom: AppValues.size_16,
                      top: AppValues.size_16),
                  decoration: BoxDecoration(
                    borderRadius: BorderRadius.circular(AppValues.size_16),
                    color: viewModel.detailGame?.item?.status == 'Live'
                        ? AppColors.glowGreen
                        : AppColors.pink,
                  ),
                  child: Center(
                      child: Text(viewModel.detailGame?.item?.status ?? '')),
                )
              ],
              pinned: false,
              floating: false,
              snap: false,
            )
          ];
        },
        floatHeaderSlivers: true,
        body: SingleChildScrollView(
          child: Container(
            color: const Color(0xFF313640),
            height: MediaQuery.of(context).size.height,
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Center(
                  child: SizedBox(
                    width: MediaQuery.of(context).size.width / 1.25,
                    child: Text(
                      "\"${viewModel.detailGame?.item?.shortDescription ?? ''}\"",
                      style: const TextStyle(
                          fontStyle: FontStyle.italic,
                          color: AppColors.whiteborderinput),
                    ),
                  ),
                ),
                Padding(
                  padding: const EdgeInsets.all(AppValues.size_16),
                  child: Text(
                      "About ${viewModel.detailGame?.item?.title ?? ''}",
                      style: const TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: AppValues.size_20,
                          color: AppColors.whitesmokke)),
                ),
                Flexible(
                    child: SingleChildScrollView(
                  child: Container(
                    padding: const EdgeInsets.symmetric(
                        horizontal: AppValues.size_16),
                    child: Text(
                      viewModel.detailGame?.item?.description ?? '',
                      style: const TextStyle(
                          fontStyle: FontStyle.normal,
                          color: AppColors.whitesmokke),
                    ),
                  ),
                )),
                const Padding(
                  padding: EdgeInsets.all(AppValues.size_16),
                  child: Text("Additional Information",
                      style: TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: AppValues.size_20,
                          color: AppColors.whitesmokke)),
                ),
                Padding(
                  padding:
                      const EdgeInsets.symmetric(horizontal: AppValues.size_16),
                  child: getAdditionalInfo(viewModel.detailGame),
                ),
                const Padding(
                  padding: EdgeInsets.only(
                      top: AppValues.size_16,
                      left: AppValues.size_16,
                      right: AppValues.size_16),
                  child: Text("Screenshots",
                      style: TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: AppValues.size_20,
                          color: AppColors.whitesmokke)),
                ),
                Expanded(
                    child: GridView.count(
                  crossAxisCount: _crossAxisCount,
                  childAspectRatio: _aspectRatio,
                  shrinkWrap: true,
                  children: List.generate(
                      viewModel.detailGame?.item?.screenshots.length ?? 0,
                      (index) {
                    return GestureDetector(
                        child: getGridItem(
                            {...viewModel.detailGame?.item?.screenshots ?? []},
                            index));
                  }),
                ))
              ],
            ),
          ),
        ),
      ),
    );
  }

  Row getAdditionalInfo(SetModel<GameDetailModel>? data) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      children: [
        Expanded(
            child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            const Text("Title",
                style: TextStyle(
                    fontWeight: FontWeight.bold,
                    fontSize: AppValues.size_14,
                    color: Colors.grey)),
            Text(data?.item?.title ?? '',
                overflow: TextOverflow.ellipsis,
                style: const TextStyle(
                    fontWeight: FontWeight.bold,
                    fontSize: AppValues.size_14,
                    color: AppColors.whitesmokke)),
            const SizedBox(
              height: AppValues.size_16,
            ),
            const Text("Publisher",
                style: TextStyle(
                    fontWeight: FontWeight.bold,
                    fontSize: AppValues.size_14,
                    color: Colors.grey)),
            Text(data?.item?.publisher ?? '',
                overflow: TextOverflow.ellipsis,
                style: const TextStyle(
                    fontWeight: FontWeight.bold,
                    fontSize: AppValues.size_14,
                    color: AppColors.whitesmokke)),
            const SizedBox(
              height: AppValues.size_8,
            ),
            const Text("Genre",
                style: TextStyle(
                    fontWeight: FontWeight.bold,
                    fontSize: AppValues.size_14,
                    color: Colors.grey)),
            Text(data?.item?.genre ?? '',
                overflow: TextOverflow.ellipsis,
                style: const TextStyle(
                    fontWeight: FontWeight.bold,
                    fontSize: AppValues.size_14,
                    color: AppColors.whitesmokke)),
            const SizedBox(
              height: AppValues.size_8,
            ),
          ],
        )),
        SizedBox(
          width: AppValues.size_4,
        ),
        Expanded(
            child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            const Text("Developer",
                style: TextStyle(
                    fontWeight: FontWeight.bold,
                    fontSize: AppValues.size_14,
                    color: Colors.grey)),
            Text(data?.item?.developer ?? '',
                overflow: TextOverflow.ellipsis,
                style: const TextStyle(
                    fontWeight: FontWeight.bold,
                    fontSize: AppValues.size_14,
                    color: AppColors.whitesmokke)),
            const SizedBox(
              height: AppValues.size_16,
            ),
            const Text("Release Date",
                style: TextStyle(
                    fontWeight: FontWeight.bold,
                    fontSize: AppValues.size_14,
                    color: Colors.grey)),
            Text(data?.item?.releaseDate.toString() ?? '',
                style: const TextStyle(
                  fontWeight: FontWeight.bold,
                  fontSize: AppValues.size_14,
                  color: AppColors.whitesmokke,
                  overflow: TextOverflow.ellipsis,
                )),
            const SizedBox(
              height: AppValues.size_8,
            ),
            const Text("Platform",
                style: TextStyle(
                    fontWeight: FontWeight.bold,
                    fontSize: AppValues.size_14,
                    color: Colors.grey)),
            Text(data?.item?.platform ?? '',
                overflow: TextOverflow.ellipsis,
                style: const TextStyle(
                    fontWeight: FontWeight.bold,
                    fontSize: AppValues.size_14,
                    color: AppColors.whitesmokke)),
            const SizedBox(
              height: AppValues.size_8,
            ),
          ],
        )),
      ],
    );
  }

  GridTile getGridItem(Set<Screenshot> data, int index) {
    return GridTile(
      child: Container(
        padding: EdgeInsets.symmetric(horizontal: AppValues.size_4),
        child: ClipRRect(
            borderRadius: BorderRadius.circular(AppValues.size_4),
            child: Image.network(
              data.elementAt(index).image,
            )),
      ),
    );
  }
}
