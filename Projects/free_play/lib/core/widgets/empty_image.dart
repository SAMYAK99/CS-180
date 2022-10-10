import 'package:flutter/material.dart';

class EmptyImage extends StatelessWidget {
  const EmptyImage({
    Key? key,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      width: double.infinity,
      height: 120,
      alignment: Alignment.center,
      color: Colors.grey.shade200,
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.center,
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Icon(Icons.error, color: Colors.grey, size: 30),
          SizedBox(height: 8),
          Text("Image not found"),
        ],
      ),
    );
  }
}
