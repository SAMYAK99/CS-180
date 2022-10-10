import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:free_play/app/ui/home/home.view.dart';
import 'package:free_play/app/ui/onboarding/onboarding_vm.dart';
import 'package:free_play/app/ui/onboarding/widget/onboarding_widget.dart';
import 'package:free_play/core/assets/app_images.dart';
import 'package:free_play/core/style/app_color.dart';
import 'package:free_play/core/style/app_values.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:pmvvm/pmvvm.dart';

class OnboardingScreen extends StatelessWidget {
  const OnboardingScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: OnboardingScreenView(),
      debugShowCheckedModeBanner: false,
    );
  }
}

class OnboardingScreenView extends StatefulWidget {
  @override
  _OnboardingScreenState createState() => _OnboardingScreenState();
}

class _OnboardingScreenState extends State<OnboardingScreenView> {
  PageController _controller = PageController();
  int currentIndex = 0;

  onChangedSlide(int index) {
    setState(() {
      currentIndex = index;
    });
  }

  @override
  void initState() {
    super.initState();
    _controller = PageController();
  }

  @override
  void dispose() {
    _controller.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: SafeArea(
        child: Stack(
          alignment: Alignment.center,
          children: [
            PageView(
              onPageChanged: onChangedSlide,
              controller: _controller,
              children: const <Widget>[
                OnboardingPlaceholder(
                    image: AppImages.imgOnboarding1,
                    titleOnboarding: "Find Free Game",
                    descOnboarding:
                        "Temukan berbagai informasi game gratis yang bisa kamu mainkan di platform kesayanganmu"),
                OnboardingPlaceholder(
                    image: AppImages.imgOnboarding2,
                    titleOnboarding: "Choose The Game",
                    descOnboarding:
                        "Pilih game yang ingin kamu tahu informasinya, kamu bisa pilih berdasarkan genre kesukaanmu"),
                OnboardingPlaceholder(
                    image: AppImages.imgOnboarding3,
                    titleOnboarding: "See The Detail",
                    descOnboarding:
                        "Dapatkan informasi lengkap tentang game yang kamu suka agar kamu tahu apakah game ini cocok untukmu")
              ],
            ),
            Positioned(
              bottom: 60,
              left: 32,
              child: Row(
                mainAxisSize: MainAxisSize.max,
                mainAxisAlignment: MainAxisAlignment.center,
                crossAxisAlignment: CrossAxisAlignment.center,
                children: <Widget>[
                  Indicator(
                    positionIndex: 0,
                    currentIndex: currentIndex,
                  ),
                  const SizedBox(
                    width: 10,
                  ),
                  Indicator(
                    positionIndex: 1,
                    currentIndex: currentIndex,
                  ),
                  const SizedBox(
                    width: 10,
                  ),
                  Indicator(
                    positionIndex: 2,
                    currentIndex: currentIndex,
                  ),
                ],
              ),
            ),
            Positioned(
              bottom: 60,
              right: 32,
              child: Row(
                children: [
                  Visibility(
                      visible: currentIndex > 0 ? true : false,
                      child: GestureDetector(
                          onTap: () {
                            if (currentIndex == 2) {
                              onChangedSlide(1);
                              _controller.animateToPage(1,
                                  duration: Duration(milliseconds: 500),
                                  curve: Curves.ease);
                            } else if (currentIndex == 1) {
                              onChangedSlide(0);
                              _controller.animateToPage(0,
                                  duration: Duration(milliseconds: 500),
                                  curve: Curves.ease);
                            }
                          },
                          child: Text(
                            'Back',
                            style: GoogleFonts.signika(
                                fontSize: AppValues.size_16,
                                color: AppColors.mainColor),
                          ))),
                  SizedBox(
                    width: 16,
                  ),
                  GestureDetector(
                      onTap: () {
                        if (currentIndex == 0) {
                          onChangedSlide(1);
                          _controller.animateToPage(1,
                              duration: Duration(milliseconds: 500),
                              curve: Curves.ease);
                        } else if (currentIndex == 1) {
                          onChangedSlide(2);
                          _controller.animateToPage(2,
                              duration: Duration(milliseconds: 500),
                              curve: Curves.ease);
                        } else {
                          Navigator.pushReplacement(
                              context,
                              MaterialPageRoute(
                                  builder: (context) => HomeScreen()));
                        }
                      },
                      child: Text(
                        currentIndex == 2 ? 'Finish' : 'Next',
                        style: GoogleFonts.signika(
                            fontSize: AppValues.size_16,
                            color: AppColors.mainColor),
                      ))
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }
}
