import 'package:flutter/material.dart';
import 'package:free_play/app/ui/splash/splash.vm.dart';
import 'package:free_play/core/assets/app_images.dart';
import 'package:pmvvm/pmvvm.dart';

class SplashScreen extends StatelessWidget {
  const SplashScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MVVM<SplashScreenVm>(
      view: () => _SplashScreenView(),
      viewModel: SplashScreenVm(),
    );
  }
}

class _SplashScreenView extends StatelessView<SplashScreenVm> {
  const _SplashScreenView({Key? key}) : super(key: key);

  @override
  Widget render(BuildContext context, SplashScreenVm viewModel) {
    return Scaffold(
      body: SafeArea(
        child: Container(
          alignment: Alignment.center,
          decoration: const BoxDecoration(
            image: DecorationImage(
              image: AssetImage(AppImages.imgSplashScreen),
              fit: BoxFit.cover,
            ),
          ),
        ),
      ),
    );
  }
}
