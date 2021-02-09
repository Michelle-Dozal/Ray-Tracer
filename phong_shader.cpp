#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
    vec3 color;
    vec3 specular;
    vec3 diffuse;
    vec3 light_color;
    vec3 l;
    vec3 r;
    double sintensity;
    double dintensity;
   // TODO;
  vec3 ambient = world.ambient_color * world.ambient_intensity * color_ambient;
	color = ambient;	
  for(unsigned int i = 0; i < world.lights.size(); i++){
	
	
	 l = world.lights[i]->position - intersection_point; 
         r = (-l + 2 * dot(l, normal) * normal).normalized();
	light_color = world.lights[i]->Emitted_Light(l);
	
	dintensity = std::max(dot(normal, l.normalized()), 0.0);
	sintensity = pow(std::max(dot(r, -ray.direction), 0.0), specular_power); 
	
	if(world.enable_shadows){	
	Ray x(intersection_point, l);
	Hit hit = world.Closest_Intersection(x);
		if(hit.dist > l.magnitude()){	
	diffuse += color_diffuse * light_color * dintensity;
	specular += color_specular * light_color * sintensity;}

	 }
	
	else{
	diffuse += color_diffuse * light_color * dintensity;
	specular += color_specular * light_color *sintensity; }
	}  

	if(debug_pixel){
	std::cout << "ambient: " << ambient << std::endl;
	std::cout << "diffuse: " << diffuse <<std::endl;
	std::cout << "specular: " << specular <<std::endl;
	std::cout << "normal: " << normal <<std::endl;}
	
	color += diffuse + specular;

   return color;
}
