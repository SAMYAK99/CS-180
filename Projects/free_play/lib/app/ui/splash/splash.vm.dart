import 'dart:async';

import 'package:flutter/material.dart';
import 'package:free_play/app/ui/onboarding/onboarding_view.dart';
import 'package:pmvvm/pmvvm.dart';

class SplashScreenVm extends ViewModel {
  @override
  void init() {
    super.init();
    Timer(
        Duration(seconds: 3),
        () => Navigator.pushReplacement(context,
            MaterialPageRoute(builder: (context) => OnboardingScreen())));
  }
}
