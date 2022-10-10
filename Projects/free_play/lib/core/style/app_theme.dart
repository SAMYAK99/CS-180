import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'app_color.dart';

class AppTheme {
  static final main = ThemeData(
    scaffoldBackgroundColor: AppColors.blackBackground,
    visualDensity: VisualDensity.adaptivePlatformDensity,
    primaryColor: AppColors.tealPrimary,
    canvasColor: Colors.white,
    inputDecorationTheme: InputDecorationTheme(
      filled: true,
      fillColor: Colors.grey[50],
      enabledBorder: OutlineInputBorder(
        borderRadius: BorderRadius.circular(10.0),
        borderSide: BorderSide(
          color: Colors.grey[300]!,
        ),
      ),
      disabledBorder: OutlineInputBorder(
        borderRadius: BorderRadius.circular(10.0),
        borderSide: BorderSide(
          color: Colors.grey[300]!,
        ),
      ),
      border: OutlineInputBorder(
        borderRadius: BorderRadius.circular(10),
      ),
    ),
    buttonTheme: ButtonThemeData(
      buttonColor: AppColors.bluemain,
      textTheme: ButtonTextTheme.primary,
      height: 54.0,
      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8.0)),
    ),

    /// Text Theme Of The APP
    textTheme: GoogleFonts.abelTextTheme().copyWith(
      headline1: GoogleFonts.abel(
        fontWeight: FontWeight.w400,
        fontSize: 36.0,
        color: AppColors.white,
      ),
      headline2: GoogleFonts.abel(
        fontWeight: FontWeight.w400,
        fontSize: 20.0,
        color: AppColors.white,
      ),
      headline3: GoogleFonts.abel(
        fontWeight: FontWeight.w400,
        fontSize: 16.0,
        color: AppColors.white,
      ),
      headline4: GoogleFonts.abel(
        fontWeight: FontWeight.w400,
        fontSize: 14.0,
        color: AppColors.white,
      ),
      headline5: GoogleFonts.abel(
        fontWeight: FontWeight.w400,
        fontSize: 12.0,
        color: AppColors.white,
      ),
      headline6: GoogleFonts.abel(
          fontWeight: FontWeight.w500,
          fontSize: 10.0,
          color: AppColors.fieldText),
      bodyText1: GoogleFonts.abel(fontSize: 14.0),
      bodyText2:
          GoogleFonts.abel(fontSize: 12.0, color: AppColors.blackcaption),
      button: GoogleFonts.abel(fontWeight: FontWeight.w600, fontSize: 16.0),
      caption: GoogleFonts.abel(fontWeight: FontWeight.w400, fontSize: 10.0),
    ),
    primaryTextTheme: TextTheme(
        headline6:
            TextStyle(color: AppColors.bluemain, fontWeight: FontWeight.bold)),
    appBarTheme: AppBarTheme(
      color: AppColors.blackAppbar,
      elevation: 0,
      iconTheme: IconThemeData(
        color: AppColors.tealPrimary,
      ),
    ),
    dividerColor: Colors.grey[100],
  );

  static final light = ThemeData(
    scaffoldBackgroundColor: AppColors.whitesmokke,
    visualDensity: VisualDensity.adaptivePlatformDensity,
    primaryColor: AppColors.tealPrimary,
    canvasColor: Colors.white,
    inputDecorationTheme: InputDecorationTheme(
      filled: true,
      fillColor: Colors.grey[50],
      enabledBorder: OutlineInputBorder(
        borderRadius: BorderRadius.circular(10.0),
        borderSide: BorderSide(
          color: Colors.grey[300]!,
        ),
      ),
      disabledBorder: OutlineInputBorder(
        borderRadius: BorderRadius.circular(10.0),
        borderSide: BorderSide(
          color: Colors.grey[300]!,
        ),
      ),
      border: OutlineInputBorder(
        borderRadius: BorderRadius.circular(10),
      ),
    ),
    buttonTheme: ButtonThemeData(
      buttonColor: AppColors.bluemain,
      textTheme: ButtonTextTheme.primary,
      height: 54.0,
      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8.0)),
    ),

    /// Text Theme Of The APP
    textTheme: GoogleFonts.openSansTextTheme().copyWith(
      headline1: GoogleFonts.openSans(
        fontWeight: FontWeight.w400,
        fontSize: 36.0,
        color: AppColors.fieldText,
      ),
      headline2: GoogleFonts.openSans(
        fontWeight: FontWeight.w400,
        fontSize: 20.0,
        color: AppColors.fieldText,
      ),
      headline3: GoogleFonts.openSans(
        fontWeight: FontWeight.w400,
        fontSize: 16.0,
        color: AppColors.fieldText,
      ),
      headline4: GoogleFonts.openSans(
        fontWeight: FontWeight.w400,
        fontSize: 14.0,
        color: AppColors.fieldText,
      ),
      headline5: GoogleFonts.openSans(
        fontWeight: FontWeight.w400,
        fontSize: 12.0,
        color: AppColors.fieldText,
      ),
      headline6: GoogleFonts.openSans(
          fontWeight: FontWeight.w500,
          fontSize: 10.0,
          color: AppColors.fieldText),
      bodyText1: GoogleFonts.openSans(fontSize: 14.0),
      bodyText2:
          GoogleFonts.openSans(fontSize: 12.0, color: AppColors.blackcaption),
      button: GoogleFonts.openSans(fontWeight: FontWeight.w600, fontSize: 16.0),
      caption:
          GoogleFonts.openSans(fontWeight: FontWeight.w400, fontSize: 10.0),
    ),
    primaryTextTheme: TextTheme(
        headline6:
            TextStyle(color: AppColors.bluemain, fontWeight: FontWeight.bold)),
    appBarTheme: AppBarTheme(
      backgroundColor: AppColors.white,
      foregroundColor: AppColors.blackAppbar,
      elevation: 0,
      iconTheme: IconThemeData(
        color: AppColors.darkBlue,
      ),
      titleTextStyle: TextStyle(
          color: Colors.black, fontWeight: FontWeight.bold, fontSize: 18),
    ),
    dividerColor: Colors.grey[100],
  );
}
