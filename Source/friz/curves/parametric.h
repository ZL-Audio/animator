//
// Copyright (c) 2020 Brett g Porter. All Rights Reserved.
//

#pragma once


#include "animatedValue.h"

namespace friz 
{


/**
 * @class Parametric
 * 
 *
 * @brief A class that can generate different parametric easing curves. 
 * 
 *        We use formulas that are available (and demonstrated!) on 
 *        https://easings.net
 * 
 * 
 */

class Parametric : public TimedValue 
{
public:

   // All the curves are generated by a function that accepts a float
   // between 0..1 (percentage of the curve completion) and returns a 
   // float that's typically between 0..1 (curve position) but may overshoot
   // that 0..1 range. 
   using CurveFn = std::function<float(float)>;

   enum CurveType 
   {
      kLinear = 0,
      kEaseInSine, 
      kEaseOutSine, 
      kEaseInOutSine, 
      kEaseInQuad,
      kEaseOutQuad, 
      kEaseInOutQuad,
      kEaseInCubic, 
      kEaseOutCubic,
      kEaseInOutCubic, 
      kEaseInQuartic, 
      kEaseOutQuartic,
      kEaseInOutQuartic,
      kEaseInQuintic,
      kEaseOutQuintic, 
      kEaseInOutQuintic,
      kEaseInExpo,
      kEaseOutExpo,
      kEaseInOutExpo,
      kEaseInCirc,
      kEaseOutCirc,
      kEaseInOutCirc,
      kEaseInBack,
      kEaseOutBack,
      kEaseInOutBack,
      kEaseInElastic,
      kEaseOutElastic,
      kEaseInOutElastic,
      kEaseInBounce, 
      kEaseOutBounce, 
      kEaseInOutBounce
   };

   /**
    * @brief Construct a new Parametric object
    * 
    * @param type Type of curve to use. 
    * @param startVal 
    * @param endVal  
    * @param duration # of frames. 
    */
   Parametric(CurveType type, float startVal, float endVal, int duration);

   /**
    * @brief Set a new curve function for the generator. 
    * 
    * @param curve 
    */
   void SetCurve(CurveFn curve);


private:

   float GenerateNextValue() override;

private:


   CurveFn fCurve;

   /// distance between start/end points. 
   float fDistance;   






};





}  // end namespace