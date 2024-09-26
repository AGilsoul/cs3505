/*
Name: Alex Gilsoul
Class: CS3505
Assignment: 3 - Facades and Makefiles
Description: This is the implementation file for the HaruPDF wrapper class
*/

#include "HaruPDF.h"


HaruPDF::HaruPDF() {
    // initialize basic haru components, pdf, page, and set sizes
    pdf = HPDF_New(NULL, NULL);
    page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_LEGAL, HPDF_PAGE_LANDSCAPE);
    HPDF_Page_BeginText(page);
    font = HPDF_GetFont(pdf, "Courier-Bold", NULL);
    HPDF_Page_SetFontAndSize (page, font, DEFAULTFONTSIZE);
}

void HaruPDF::placeText(int x, int y, char text) {
    // create buffer for character
    char buf[2];
    // set position with identitiy matrix (no rotation) and x,y coordinates
    HPDF_Page_SetTextMatrix(page,
                                1, 0, 0, 1,
                                x, y);
    buf[0] = text;
    buf[1] = 0;
    // write character buffer to page
    HPDF_Page_ShowText(page, buf);
}

void HaruPDF::save(const char* fileName) {
    HPDF_Page_EndText(page);
    HPDF_SaveToFile(pdf, fileName);
    HPDF_Free(pdf);
}

void HaruPDF::setFontSize(int fontSize) {
    if (fontSize > MAXFONT) {
        fontSize = MAXFONT;
    }
    HPDF_Page_SetFontAndSize(page, font, fontSize);
}