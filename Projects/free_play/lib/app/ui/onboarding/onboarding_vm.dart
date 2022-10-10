import 'package:flutter/material.dart';
import 'package:pmvvm/pmvvm.dart';

class OnboardingVm extends ViewModel {
  PageController pageController = PageController();
  final currentIndex = 0.observable('index');

  @override
  void init() {
    super.init();
    observe([currentIndex]);
  }

  onChangedFunction(int index) {
    currentIndex.setValue(index, action: 'ADD');
    notifyListeners();
  }
}
