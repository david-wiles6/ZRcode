# Introduction

This folder is all about vectors and getting a little bit of intuition in using them, it looks kind of math-y at first, but like the rest of ZR stuff, it's mostlty jsut coding.

# Doing Vector Math

In this file, I will show you how to do vector math in the ZR IDE. We will talk about how to do vector subtraction, the magnitude, the inner product, and the cross product, and why those things are useful. Once again, its only important to know what is going on behind the scenes insofar as you can get the needed information from the function.
 
## mathVecSubtract

This fuction is in the form of mathVecSubtract(float\[n\] c,float\[n\] a, float\[n\] b, n) where c = a - b and n is the length of those arrays, which should almost always be 3. This is important because c will always be a vector pointing from b to a with length as the distance between a and b. You will want this for attitude (where you are pointing at) and if you want more fine control over velocity as opposed to using setPositionTarget. 

## mathVecMagnitude

This function is in the form mathVecMagnitude(float\[n\] a, n) where the return value is the length of the vector a, and n is the number of elements in a, which should almost always be 3. The length of a vector is important because it can represent the distance between two objects, the distance between you and the origin, and it is importnat for getting useful information out of the mathVecInner function described below.

## mathVecInner

This function is in the form of mathVecInner(float\[n\] a, float\[n\] b, n) where the return value is a\*b and n is the length of the arrays, once again it should be 3 in almost every case. a\*b is important because a\*b = magnitude(a)\*magnitude(b)\*cos(C) where C is the angle between them. The biggest use for this function is to get the angle between two vectors, so to get C, take a\*b and divide it by the magnitude of a and the magnitude of b, then do acosf on that, shown in the example.

## mathVecCross

This function is useful for getting a vector that is perpendicular, or more precisely orthogonal, to two other vectors. This function is in the form mathVecCross(float\[n\] c, float\[n\] a, float\[n\] b, n) where n is the length of the arrays and c = a x b. Magnitude(c) is also equal to magnitude(a)\*magnitude(b)\*sin(C) where C is the angle between a and b. 
