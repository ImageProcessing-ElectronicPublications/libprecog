/*
    MIT License

    Copyright (c) 2017 Alexander Zaitsev

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#ifndef UFOCR_BINARIZATION_HPP
#define UFOCR_BINARIZATION_HPP

#include "opencv2/core.hpp"

namespace prl
{
enum class BinarizationMethod
{
    Otsu, /*!< Otsu global binarization */
    Adaptive,
    OtsuMA,
    Niblack, /*!< Niblack adaptive binarization */
    Sauvola, /*!< Sauvola adaptive binarization */
    MaxEntropy, /*!< Maximum entropy global binarization */
    Bradley, /*!< Bradley adaptive binarization */
    Iterative, /*!< Global iterative binarization */
    Bernsen, /*!< Bernsen adaptive binarization */
    Gatos /*!< Ga'tos adaptive binarization */
};

//TODO: Rewrite all binarization algorithms. By default should use OtsuThreshold.
extern "C" void binarize(const cv::Mat& src, cv::Mat& dst, BinarizationMethod method = BinarizationMethod::Otsu);
}

#endif //UFOCR_BINARIZATION_HPP
