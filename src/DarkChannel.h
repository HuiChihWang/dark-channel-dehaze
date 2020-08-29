//
// Created by Hui Chih Wang on 2020/8/28.
//
#ifndef DEHAZE_DARKCHANNEL_H
#define DEHAZE_DARKCHANNEL_H

#include "opencv2/core.hpp"


struct TDarkChannelSetting {
    cv::Size sizePatch = cv::Size{7,7};

};

class CDarkChannel {

public:
    CDarkChannel() = default;
    ~CDarkChannel();

    void SetImage(const cv::Mat& matImage);
    void SetParameter(TDarkChannelSetting* pTSetting);

    bool CalDarkChannel();
    const cv::Mat& GetDarkChannel();


    void ClearResult();

private:
    static cv::Mat FilterRGBMin(const cv::Mat& matImage);
    static cv::Mat FilterGrayMin(const cv::Mat &matImage, const cv::Size sizePatch);

    cv::Mat m_matImage;
    cv::Mat m_matDarkChannel;
    TDarkChannelSetting* m_pTSetting = new TDarkChannelSetting;
};


#endif //DEHAZE_DARKCHANNEL_H
