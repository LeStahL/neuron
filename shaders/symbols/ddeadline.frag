#version 130

void dlinesegment(in vec2 x, in vec2 p1, in vec2 p2, out float d);

const int npts1 = 368;
const float path1[npts1] = float[npts1](0.114,-0.123,0.102,-0.137,0.102,-0.137,0.040,-0.137,0.040,-0.137,-0.013,-0.078,-0.013,-0.078,-0.064,-0.137,-0.064,-0.137,-0.153,-0.137,-0.153,-0.137,-0.165,-0.123,-0.165,-0.123,-0.176,-0.137,-0.176,-0.137,-0.380,-0.137,-0.380,-0.137,-0.500,0.002,-0.500,0.002,-0.412,0.104,-0.412,0.104,-0.393,0.104,-0.393,0.104,-0.480,0.002,-0.480,0.002,-0.467,0.002,-0.467,0.002,-0.380,0.104,-0.380,0.104,-0.297,0.104,-0.297,0.104,-0.253,0.054,-0.253,0.054,-0.238,0.073,-0.238,0.073,-0.259,0.073,-0.259,0.073,-0.288,0.104,-0.288,0.104,0.030,0.104,0.030,0.104,-0.039,0.023,-0.039,0.023,-0.196,0.023,-0.196,0.023,-0.205,0.033,-0.205,0.033,-0.228,0.002,-0.228,0.002,-0.044,0.002,-0.044,0.002,0.042,0.104,0.042,0.104,0.067,0.104,0.067,0.104,-0.020,0.002,-0.020,0.002,-0.011,0.002,-0.011,0.002,0.077,0.104,0.077,0.104,0.090,0.104,0.090,0.104,0.057,0.145,0.057,0.145,0.123,0.145,0.123,0.145,0.156,0.104,0.156,0.104,0.357,0.105,0.357,0.105,0.332,0.072,0.332,0.072,0.260,0.072,0.260,0.072,0.301,0.023,0.301,0.023,0.404,0.145,0.404,0.145,0.470,0.145,0.470,0.145,0.349,0.001,0.349,0.001,0.255,0.001,0.255,0.001,0.195,0.072,0.195,0.072,0.185,0.072,0.185,0.072,0.251,-0.009,0.251,-0.009,0.352,-0.009,0.352,-0.009,0.481,0.145,0.481,0.145,0.500,0.145,0.500,0.145,0.376,-0.009,0.376,-0.009,0.442,-0.086,0.442,-0.086,0.143,-0.086,0.143,-0.086,0.127,-0.107,0.127,-0.107,0.396,-0.107,0.396,-0.107,0.428,-0.145,0.428,-0.145,0.133,-0.145,0.133,-0.145,0.114,-0.123,-0.155,-0.050,-0.131,-0.050,-0.131,-0.050,-0.094,-0.093,-0.094,-0.093,-0.047,-0.039,-0.047,-0.039,-0.144,-0.038,-0.144,-0.038,-0.240,-0.037,-0.240,-0.037,-0.252,-0.025,-0.252,-0.025,-0.263,-0.037,-0.263,-0.037,-0.398,-0.039,-0.398,-0.039,-0.340,-0.107,-0.340,-0.107,-0.180,-0.107,-0.180,-0.107,-0.231,-0.050,-0.231,-0.050,-0.164,-0.050,-0.164,-0.050,-0.112,-0.116,-0.112,-0.116,-0.107,-0.109,-0.107,-0.109,-0.155,-0.050,0.125,-0.038,0.032,-0.036,0.032,-0.036,0.065,0.003,0.065,0.003,0.175,0.003,0.175,0.003,0.115,0.072,0.115,0.072,0.022,-0.037,0.022,-0.037,0.073,-0.098,0.073,-0.098,0.125,-0.038,0.350,-0.056,0.336,-0.037,0.336,-0.037,0.210,-0.037,0.210,-0.037,0.200,-0.024,0.200,-0.024,0.172,-0.056,0.172,-0.056,0.350,-0.056,-0.281,0.023,-0.299,0.023,-0.299,0.023,-0.341,0.071,-0.341,0.071,-0.401,0.002,-0.401,0.002,-0.297,0.002,-0.297,0.002,-0.281,0.023,-0.063,0.073,-0.172,0.073,-0.172,0.073,-0.186,0.055,-0.186,0.055,-0.076,0.055,-0.076,0.055,-0.063,0.073);

void ddeadline(in vec2 x, out float ret)
{
    ret = 1.;
    float da;

    float n = 0.;
    for(int i=0; i<npts1/4; ++i)
    {
        vec2 ptsi = vec2(path1[4*i], path1[4*i+1]),
            ptsip1 = vec2(path1[4*i+2], path1[4*i+3]),
            k = x-ptsi, 
            d = ptsip1-ptsi;
        
        float beta = k.x/d.x,
            alpha = d.y*k.x/d.x-k.y;
        
        n += step(.0, beta)*step(beta, 1.)*step(0., alpha);
        dlinesegment(x, ptsi, ptsip1, da);
        ret = min(ret, da);
    }
    
    ret = mix(ret, -ret, mod(n, 2.));
}
