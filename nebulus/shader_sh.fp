// SL 2012-02-08

varying vec3   v_Nrm;
varying vec2   v_Tex;
varying vec3 v_SrfPos;

uniform vec3 u_LightPos;
uniform vec3 u_Eye;
uniform float u_SpecExp;

uniform sampler2D u_Image;

void main()
{
  vec3 n = normalize(v_Nrm);
  vec3 l   = normalize(u_LightPos - v_SrfPos);
  float diffuse = max(0.0,dot(l,n));
  vec3 r = 2.0 * dot(n,l) * n - l;
  vec3 v = normalize(u_Eye - v_SrfPos);
  float specular = pow(max(0.0,dot(r,v)),30.0);
  vec4 srfclr = texture2D(u_Image,v_Tex);

  vec3 clr = srfclr.xyz * (diffuse + specular); 
  gl_FragColor = vec4(clr,1);
}
