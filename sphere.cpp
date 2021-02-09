#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
  //  TODO;
  //use lab#1 code base
  //Hit hit {this, 0, part};
  vec3 length = ray.endpoint - center;
  double a = dot(ray.direction, length);
  double b = dot(ray.direction, ray.direction);
  double c = dot(length,length)-pow(radius,2);
  double discriminant = pow(a,2) - (b * c);


   if (discriminant > 0){
	double x = (-1 * a + sqrt(discriminant))/ b;
	double y = ( -1 * a - sqrt(discriminant))/ b;
	if(x < y && x >= small_t){
	return{this,x,part};
	}
	else if(x >= y && y >= small_t){
 	return{this,y,part};
	}
}	
   return {nullptr,0,part};
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;
   // TODO; // compute the normal direction
    
    normal = (point - center);
    return normal.normalized();
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}
