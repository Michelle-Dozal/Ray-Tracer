#include "reflective_shader.h"
#include "ray.h"
#include "render_world.h"

vec3 Reflective_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
    vec3 color;
   // TODO; // determine the color
   // (1-k) * color + k * cast_ray(reflected ray,recursion depth) where k is the reflectivity
   // r(reflected vector direction) = 2 * dot(direction, normal)*normal + direction  
 
   //double reflectivity; 
    color = shader->Shade_Surface(ray, intersection_point, normal, recursion_depth);
     color = (1 - reflectivity) * color;
 
	vec3 r = 2 * dot(-ray.direction, normal)* normal + ray.direction;
	Ray x(intersection_point, r);

	if(world.recursion_depth_limit > recursion_depth){
	 color +=  reflectivity * world.Cast_Ray(x, ++recursion_depth);
	}
	

    return color;
}
