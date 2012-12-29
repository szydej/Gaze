/*
 * geometry.hpp
 *
 *  Created on: Nov 9, 2012
 *      Author: krigu
 */

#ifndef GEOMETRY_HPP_
#define GEOMETRY_HPP_

#include <vector>

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

/**
 * Calculate to absolute distance between to points
 */
int calcPointDistance(cv::Point *point1, cv::Point *point2);

/**
 * Calculate to absolute distance between to points
 */
float calcPoint2fDistance(cv::Point2f point1, cv::Point2f point2);

/**
 * Calculates the barycenter of a Rect
 */
cv::Point calcRectBarycenter(cv::Rect& rect);

double calcAngle(cv::Point start, cv::Point end);

cv::Point2f calcAverage(std::vector<cv::Point2f> points);

/**
 * Calculates the median distance between a reference point and a vector of points
 * 
 * @param referencePoint reference point
 * @param scores vector of points
 * @return median point
 */
cv::Point2f calcMedianPoint(cv::Point2f reference, std::vector< cv::Point2f > scores);

/**
 * this function tries to find the circle that fits best (least squares)
 * to the given points. the code is based on our coaches matlab code fitCircle.m
 * 
 * @param x the x coordinate
 * @param y the y coordinate
 * @param radius the new radius
 * @param pointsToFit the points to which a circle should be fit
 */
void bestFitCircle(float * x, float * y, float * radius,
		std::vector<cv::Point2f> pointsToFit);

/**
 * 
 * @param points
 * @param tolerance
 * @return 
 */
bool isRectangle(std::vector< cv::Point > points, int tolerance);

bool isRectangle(cv::Point p1, cv::Point p2, cv::Point p3, cv::Point p4, int tolerance);

void orientateFourPoints(std::vector< cv::Point >& points );

#endif /* GEOMETRY_HPP_ */
