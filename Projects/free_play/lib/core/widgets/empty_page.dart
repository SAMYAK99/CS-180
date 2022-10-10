import 'package:flutter/material.dart';

class EmptyPage extends StatelessWidget {
  const EmptyPage({
    Key? key,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Center(
      child: SizedBox(
        width: double.infinity,
        height: 300,
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.center,
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Icon(Icons.search, color: Colors.grey, size: 30),
            SizedBox(height: 8),
            Text("Data is not found"),
          ],
        ),
      ),
    );
  }
}
