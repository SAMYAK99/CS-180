import 'package:flutter/material.dart';
import 'package:flutter_svg/flutter_svg.dart';
import 'package:free_play/core/style/app_color.dart';
import 'package:free_play/core/style/app_values.dart';
import 'package:google_fonts/google_fonts.dart';

class Indicator extends StatelessWidget {
  final int positionIndex, currentIndex;

  const Indicator({required this.currentIndex, required this.positionIndex});

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 12,
      width: 12,
      decoration: BoxDecoration(
          border: Border.all(color: Color(0xFFFF2273)),
          color:
              positionIndex == currentIndex ? Color(0xFFFF2273) : Colors.transparent,
          borderRadius: BorderRadius.circular(100)),
    );
  }
}

class OnboardingPlaceholder extends StatelessWidget {
  final String image, titleOnboarding, descOnboarding;

  const OnboardingPlaceholder(
      {Key? key,
      required this.image,
      required this.titleOnboarding,
      required this.descOnboarding})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
        decoration: BoxDecoration(
            borderRadius: BorderRadius.circular(16), color: AppColors.white),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Container(
              padding: EdgeInsets.all(AppValues.size_18),
              width: double.infinity,
              height: 200,
              child: SvgPicture.asset(image),
            ),
            Padding(
              padding: EdgeInsets.all(AppValues.size_16),
              child: Column(
                children: [
                  SizedBox(
                    height: 16,
                  ),
                  Text(
                    titleOnboarding,
                    textAlign: TextAlign.center,
                    style: GoogleFonts.signika(
                      fontSize: 20,
                      fontWeight: FontWeight.bold,
                      color: AppColors.black,
                    ),
                  ),
                  SizedBox(
                    height: 8,
                  ),
                  Text(descOnboarding,
                      textAlign: TextAlign.center,
                      style: GoogleFonts.signika(
                        fontSize: 14,
                        color: AppColors.greyChartLabel,
                      ))
                ],
              ),
            )
          ],
        ));
  }
}
