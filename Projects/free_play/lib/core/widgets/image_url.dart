import 'package:flutter/material.dart';
import 'package:free_play/core/style/app_color.dart';

import 'empty_image.dart';

class ImageUrl extends StatelessWidget {
  final String fileName;
  final BoxFit? fit;

  const ImageUrl({this.fit, required this.fileName});

  @override
  Widget build(BuildContext context) {
    return fileName != ""
        ? Image.network(fileName, fit: fit, loadingBuilder:
            (BuildContext context, Widget child,
                ImageChunkEvent? loadingProgress) {
            if (loadingProgress == null) {
              return child;
            } else {
              return Center(
                child: CircularProgressIndicator(
                  valueColor: AlwaysStoppedAnimation<Color>(AppColors.darkBlue),
                ),
              );
            }
          }, errorBuilder:
            (BuildContext context, Object exception, StackTrace? stackTrace) {
            return EmptyImage();
          })
        : EmptyImage();
  }
}
