// Main.cpp

#include "Main.h"
#include "driverSystem.cpp"

///////////////////////////////////////////////////////////////////////////////////////////////////
int main(void) {
    UI u1;
    u1.menu();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void drawRedRectangleAroundPlate(cv::Mat& imgOriginalScene, PossiblePlate& licPlate) {
    cv::Point2f p2fRectPoints[4];

    licPlate.rrLocationOfPlateInScene.points(p2fRectPoints);            

    for (int i = 0; i < 4; i++) {                                       
        cv::line(imgOriginalScene, p2fRectPoints[i], p2fRectPoints[(i + 1) % 4], SCALAR_RED, 2);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void writeLicensePlateCharsOnImage(cv::Mat& imgOriginalScene, PossiblePlate& licPlate) {
    cv::Point ptCenterOfTextArea;                  
    cv::Point ptLowerLeftTextOrigin;                

    int intFontFace = CV_FONT_HERSHEY_SIMPLEX;                              
    double dblFontScale = (double)licPlate.imgPlate.rows / 30.0;            
    int intFontThickness = (int)std::round(dblFontScale * 1.5);             
    int intBaseline = 0;

    cv::Size textSize = cv::getTextSize(licPlate.strChars, intFontFace, dblFontScale, intFontThickness, &intBaseline);      

    ptCenterOfTextArea.x = (int)licPlate.rrLocationOfPlateInScene.center.x;         

    if (licPlate.rrLocationOfPlateInScene.center.y < (imgOriginalScene.rows * 0.75)) {      
                                                                                            
        ptCenterOfTextArea.y = (int)std::round(licPlate.rrLocationOfPlateInScene.center.y) + (int)std::round((double)licPlate.imgPlate.rows * 1.6);
    }
    else {                                                                                
                                                                                          
        ptCenterOfTextArea.y = (int)std::round(licPlate.rrLocationOfPlateInScene.center.y) - (int)std::round((double)licPlate.imgPlate.rows * 1.6);
    }

    ptLowerLeftTextOrigin.x = (int)(ptCenterOfTextArea.x - (textSize.width / 2));        
    ptLowerLeftTextOrigin.y = (int)(ptCenterOfTextArea.y + (textSize.height / 2));          
                                                                                     
    cv::putText(imgOriginalScene, licPlate.strChars, ptLowerLeftTextOrigin, intFontFace, dblFontScale, SCALAR_YELLOW, intFontThickness);
}

