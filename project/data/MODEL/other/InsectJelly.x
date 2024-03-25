xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 204;
 -0.20686;39.73390;-41.84658;,
 29.38320;39.73390;-29.59001;,
 27.13079;23.71992;-27.33758;,
 -0.20686;23.71992;-38.66116;,
 41.63980;39.73390;0.00000;,
 38.45435;23.71992;0.00000;,
 29.38320;39.73390;29.59001;,
 27.13079;23.71992;27.33758;,
 -0.20686;39.73390;41.84658;,
 -0.20686;23.71992;38.66116;,
 -29.79684;39.73390;29.59001;,
 -27.54446;23.71992;27.33758;,
 -42.05343;39.73390;0.00000;,
 -38.86802;23.71992;0.00000;,
 -29.79684;39.73390;-29.59001;,
 -27.54446;23.71992;-27.33758;,
 -0.20686;39.73390;-41.84658;,
 -0.20686;23.71992;-38.66116;,
 20.71641;10.14388;-20.92329;,
 -0.20686;10.14388;-29.59001;,
 29.38320;10.14388;0.00000;,
 20.71641;10.14388;20.92329;,
 -0.20686;10.14388;29.59001;,
 -21.13012;10.14388;20.92329;,
 -29.79684;10.14388;0.00000;,
 -21.13012;10.14388;-20.92329;,
 -0.20686;10.14388;-29.59001;,
 11.11674;1.07273;-11.32360;,
 -0.20686;1.07273;-16.01397;,
 15.80707;1.07273;0.00000;,
 11.11674;1.07273;11.32360;,
 -0.20686;1.07273;16.01397;,
 -11.53044;1.07273;11.32360;,
 -16.22083;1.07273;0.00000;,
 -11.53044;1.07273;-11.32360;,
 -0.20686;1.07273;-16.01397;,
 -0.20686;0.28194;0.00000;,
 -0.20686;0.28194;0.00000;,
 -0.20686;0.28194;0.00000;,
 -0.20686;0.28194;0.00000;,
 -0.20686;0.28194;0.00000;,
 -0.20686;0.28194;0.00000;,
 -0.20686;0.28194;0.00000;,
 -0.20686;0.28194;0.00000;,
 36.23272;39.38019;0.00000;,
 37.56681;40.13465;0.00000;,
 26.50320;40.13465;-26.70999;,
 25.55985;39.38019;-25.76665;,
 40.78771;40.44717;0.00000;,
 28.78062;40.44717;-28.98749;,
 44.00849;40.13465;0.00000;,
 31.05811;40.13465;-31.26496;,
 45.34270;39.38019;0.00000;,
 32.00152;39.38019;-32.20831;,
 44.00849;38.62572;0.00000;,
 31.05811;38.62572;-31.26496;,
 40.78771;38.31320;0.00000;,
 28.78062;38.31320;-28.98749;,
 37.56681;38.62572;0.00000;,
 26.50320;38.62572;-26.70999;,
 36.23272;39.38019;0.00000;,
 25.55985;39.38019;-25.76665;,
 -0.20686;40.13465;-37.77364;,
 -0.20686;39.38019;-36.43954;,
 -0.20686;40.44717;-40.99449;,
 -0.20686;40.13465;-44.21531;,
 -0.20686;39.38019;-45.54945;,
 -0.20686;38.62572;-44.21531;,
 -0.20686;38.31320;-40.99449;,
 -0.20686;38.62572;-37.77364;,
 -0.20686;39.38019;-36.43954;,
 -26.91684;40.13465;-26.70999;,
 -25.97350;39.38019;-25.76665;,
 -29.19434;40.44717;-28.98749;,
 -31.47180;40.13465;-31.26496;,
 -32.41515;39.38019;-32.20831;,
 -31.47180;38.62572;-31.26496;,
 -29.19434;38.31320;-28.98749;,
 -26.91684;38.62572;-26.70999;,
 -25.97350;39.38019;-25.76665;,
 -37.98049;40.13465;0.00000;,
 -36.64638;39.38019;0.00000;,
 -41.20134;40.44717;0.00000;,
 -44.42217;40.13465;0.00000;,
 -45.75632;39.38019;0.00000;,
 -44.42217;38.62572;0.00000;,
 -41.20134;38.31320;0.00000;,
 -37.98049;38.62572;0.00000;,
 -36.64638;39.38019;0.00000;,
 -26.91684;40.13465;26.70999;,
 -25.97350;39.38019;25.76665;,
 -29.19434;40.44717;28.98749;,
 -31.47180;40.13465;31.26496;,
 -32.41515;39.38019;32.20831;,
 -31.47180;38.62572;31.26496;,
 -29.19434;38.31320;28.98749;,
 -26.91684;38.62572;26.70999;,
 -25.97350;39.38019;25.76665;,
 -0.20686;40.13465;37.77364;,
 -0.20686;39.38019;36.43954;,
 -0.20686;40.44717;40.99449;,
 -0.20686;40.13465;44.21531;,
 -0.20686;39.38019;45.54945;,
 -0.20686;38.62572;44.21531;,
 -0.20686;38.31320;40.99449;,
 -0.20686;38.62572;37.77364;,
 -0.20686;39.38019;36.43954;,
 26.50320;40.13465;26.70999;,
 25.55985;39.38019;25.76665;,
 28.78062;40.44717;28.98749;,
 31.05811;40.13465;31.26496;,
 32.00152;39.38019;32.20831;,
 31.05811;38.62572;31.26496;,
 28.78062;38.31320;28.98749;,
 26.50320;38.62572;26.70999;,
 25.55985;39.38019;25.76665;,
 37.56681;40.13465;0.00000;,
 36.23272;39.38019;0.00000;,
 40.78771;40.44717;0.00000;,
 44.00849;40.13465;0.00000;,
 45.34270;39.38019;0.00000;,
 44.00849;38.62572;0.00000;,
 40.78771;38.31320;0.00000;,
 37.56681;38.62572;0.00000;,
 36.23272;39.38019;0.00000;,
 -84.27189;21.10134;0.00000;,
 -96.51996;15.78593;-13.34947;,
 -84.37245;21.32190;-18.87904;,
 -84.27189;21.10134;0.00000;,
 -101.55164;13.49287;0.00000;,
 -84.27189;21.10134;0.00000;,
 -96.51992;15.78593;13.34947;,
 -84.27189;21.10134;0.00000;,
 -84.37238;21.32190;18.87904;,
 -84.27189;21.10134;0.00000;,
 -72.22490;26.85782;13.34947;,
 -84.27189;21.10134;0.00000;,
 -67.19326;29.15089;0.00000;,
 -84.27189;21.10134;0.00000;,
 -72.22490;26.85782;-13.34947;,
 -84.27189;21.10134;0.00000;,
 -84.37245;21.32190;-18.87904;,
 -106.91651;11.30898;-24.66663;,
 -84.47091;21.53804;-34.88390;,
 -116.21384;7.07193;0.00000;,
 -106.91651;11.30898;24.66663;,
 -84.47086;21.53804;34.88390;,
 -62.02520;31.76719;24.66663;,
 -52.72787;36.00420;0.00000;,
 -62.02520;31.76719;-24.66663;,
 -84.47091;21.53804;-34.88390;,
 -113.84304;8.27292;-32.22851;,
 -84.51637;21.63784;-45.57801;,
 -125.99060;2.73696;0.00000;,
 -113.84304;8.27292;32.22851;,
 -84.51637;21.63784;45.57801;,
 -55.18967;35.00287;32.22851;,
 -43.04206;40.53886;0.00000;,
 -55.18967;35.00287;-32.22851;,
 -84.51637;21.63784;-45.57801;,
 -0.20686;40.00657;0.00000;,
 9.59185;39.59794;-9.79871;,
 -0.20686;39.59794;-13.85745;,
 -0.20686;40.00657;0.00000;,
 13.65060;39.59794;0.00000;,
 -0.20686;40.00657;0.00000;,
 9.59185;39.59794;9.79871;,
 -0.20686;40.00657;0.00000;,
 -0.20686;39.59794;13.85745;,
 -0.20686;40.00657;0.00000;,
 -10.00556;39.59794;9.79871;,
 -0.20686;40.00657;0.00000;,
 -14.06431;39.59794;0.00000;,
 -0.20686;40.00657;0.00000;,
 -10.00556;39.59794;-9.79871;,
 -0.20686;40.00657;0.00000;,
 -0.20686;39.59794;-13.85745;,
 17.89878;39.83738;-18.10563;,
 -0.20686;39.83738;-25.60525;,
 25.39842;39.83738;0.00000;,
 17.89878;39.83738;18.10563;,
 -0.20686;39.83738;25.60525;,
 -18.31248;39.83738;18.10563;,
 -25.81209;39.83738;0.00000;,
 -18.31248;39.83738;-18.10563;,
 -0.20686;39.83738;-25.60525;,
 23.44934;39.22883;-23.65617;,
 -0.20686;39.22883;-33.45488;,
 33.24811;39.22883;0.00000;,
 23.44934;39.22883;23.65617;,
 -0.20686;39.22883;33.45488;,
 -23.86300;39.22883;23.65617;,
 -33.66172;39.22883;0.00000;,
 -23.86300;39.22883;-23.65617;,
 -0.20686;39.22883;-33.45488;,
 25.39842;39.11594;-25.60525;,
 -0.20686;39.11594;-36.21126;,
 36.00445;39.11594;0.00000;,
 25.39842;39.11594;25.60525;,
 -0.20686;39.11594;36.21126;,
 -25.81209;39.11594;25.60525;,
 -36.41810;39.11594;0.00000;,
 -25.81209;39.11594;-25.60525;,
 -0.20686;39.11594;-36.21126;;
 
 208;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;3,2,18,19;,
 4;2,5,20,18;,
 4;5,7,21,20;,
 4;7,9,22,21;,
 4;9,11,23,22;,
 4;11,13,24,23;,
 4;13,15,25,24;,
 4;15,17,26,25;,
 4;19,18,27,28;,
 4;18,20,29,27;,
 4;20,21,30,29;,
 4;21,22,31,30;,
 4;22,23,32,31;,
 4;23,24,33,32;,
 4;24,25,34,33;,
 4;25,26,35,34;,
 3;28,27,36;,
 3;27,29,37;,
 3;29,30,38;,
 3;30,31,39;,
 3;31,32,40;,
 3;32,33,41;,
 3;33,34,42;,
 3;34,35,43;,
 4;3,2,1,0;,
 4;2,5,4,1;,
 4;5,7,6,4;,
 4;7,9,8,6;,
 4;9,11,10,8;,
 4;11,13,12,10;,
 4;13,15,14,12;,
 4;15,17,16,14;,
 4;19,18,2,3;,
 4;18,20,5,2;,
 4;20,21,7,5;,
 4;21,22,9,7;,
 4;22,23,11,9;,
 4;23,24,13,11;,
 4;24,25,15,13;,
 4;25,26,17,15;,
 4;28,27,18,19;,
 4;27,29,20,18;,
 4;29,30,21,20;,
 4;30,31,22,21;,
 4;31,32,23,22;,
 4;32,33,24,23;,
 4;33,34,25,24;,
 4;34,35,26,25;,
 3;36,27,28;,
 3;37,29,27;,
 3;38,30,29;,
 3;39,31,30;,
 3;40,32,31;,
 3;41,33,32;,
 3;42,34,33;,
 3;43,35,34;,
 4;44,45,46,47;,
 4;45,48,49,46;,
 4;48,50,51,49;,
 4;50,52,53,51;,
 4;52,54,55,53;,
 4;54,56,57,55;,
 4;56,58,59,57;,
 4;58,60,61,59;,
 4;47,46,62,63;,
 4;46,49,64,62;,
 4;49,51,65,64;,
 4;51,53,66,65;,
 4;53,55,67,66;,
 4;55,57,68,67;,
 4;57,59,69,68;,
 4;59,61,70,69;,
 4;63,62,71,72;,
 4;62,64,73,71;,
 4;64,65,74,73;,
 4;65,66,75,74;,
 4;66,67,76,75;,
 4;67,68,77,76;,
 4;68,69,78,77;,
 4;69,70,79,78;,
 4;72,71,80,81;,
 4;71,73,82,80;,
 4;73,74,83,82;,
 4;74,75,84,83;,
 4;75,76,85,84;,
 4;76,77,86,85;,
 4;77,78,87,86;,
 4;78,79,88,87;,
 4;81,80,89,90;,
 4;80,82,91,89;,
 4;82,83,92,91;,
 4;83,84,93,92;,
 4;84,85,94,93;,
 4;85,86,95,94;,
 4;86,87,96,95;,
 4;87,88,97,96;,
 4;90,89,98,99;,
 4;89,91,100,98;,
 4;91,92,101,100;,
 4;92,93,102,101;,
 4;93,94,103,102;,
 4;94,95,104,103;,
 4;95,96,105,104;,
 4;96,97,106,105;,
 4;99,98,107,108;,
 4;98,100,109,107;,
 4;100,101,110,109;,
 4;101,102,111,110;,
 4;102,103,112,111;,
 4;103,104,113,112;,
 4;104,105,114,113;,
 4;105,106,115,114;,
 4;108,107,116,117;,
 4;107,109,118,116;,
 4;109,110,119,118;,
 4;110,111,120,119;,
 4;111,112,121,120;,
 4;112,113,122,121;,
 4;113,114,123,122;,
 4;114,115,124,123;,
 3;125,126,127;,
 3;128,129,126;,
 3;130,131,129;,
 3;132,133,131;,
 3;134,135,133;,
 3;136,137,135;,
 3;138,139,137;,
 3;140,141,139;,
 4;127,126,142,143;,
 4;126,129,144,142;,
 4;129,131,145,144;,
 4;131,133,146,145;,
 4;133,135,147,146;,
 4;135,137,148,147;,
 4;137,139,149,148;,
 4;139,141,150,149;,
 4;143,142,151,152;,
 4;142,144,153,151;,
 4;144,145,154,153;,
 4;145,146,155,154;,
 4;146,147,156,155;,
 4;147,148,157,156;,
 4;148,149,158,157;,
 4;149,150,159,158;,
 3;127,126,125;,
 3;126,129,128;,
 3;129,131,130;,
 3;131,133,132;,
 3;133,135,134;,
 3;135,137,136;,
 3;137,139,138;,
 3;139,141,140;,
 4;143,142,126,127;,
 4;142,144,129,126;,
 4;144,145,131,129;,
 4;145,146,133,131;,
 4;146,147,135,133;,
 4;147,148,137,135;,
 4;148,149,139,137;,
 4;149,150,141,139;,
 4;152,151,142,143;,
 4;151,153,144,142;,
 4;153,154,145,144;,
 4;154,155,146,145;,
 4;155,156,147,146;,
 4;156,157,148,147;,
 4;157,158,149,148;,
 4;158,159,150,149;,
 3;160,161,162;,
 3;163,164,161;,
 3;165,166,164;,
 3;167,168,166;,
 3;169,170,168;,
 3;171,172,170;,
 3;173,174,172;,
 3;175,176,174;,
 4;162,161,177,178;,
 4;161,164,179,177;,
 4;164,166,180,179;,
 4;166,168,181,180;,
 4;168,170,182,181;,
 4;170,172,183,182;,
 4;172,174,184,183;,
 4;174,176,185,184;,
 4;178,177,186,187;,
 4;177,179,188,186;,
 4;179,180,189,188;,
 4;180,181,190,189;,
 4;181,182,191,190;,
 4;182,183,192,191;,
 4;183,184,193,192;,
 4;184,185,194,193;,
 4;187,186,195,196;,
 4;186,188,197,195;,
 4;188,189,198,197;,
 4;189,190,199,198;,
 4;190,191,200,199;,
 4;191,192,201,200;,
 4;192,193,202,201;,
 4;193,194,203,202;;
 
 MeshMaterialList {
  4;
  208;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.398400;0.800000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  229;
  -0.000000;-0.195092;-0.980785;,
  0.693519;-0.195093;-0.693520;,
  0.980785;-0.195093;-0.000000;,
  0.693519;-0.195093;0.693520;,
  -0.000000;-0.195092;0.980785;,
  -0.693520;-0.195092;0.693520;,
  -0.980785;-0.195091;0.000000;,
  -0.693520;-0.195092;-0.693520;,
  -0.000000;-0.384551;-0.923104;,
  0.652732;-0.384552;-0.652733;,
  0.923103;-0.384552;-0.000000;,
  0.652732;-0.384552;0.652733;,
  -0.000000;-0.384551;0.923104;,
  -0.652733;-0.384551;0.652733;,
  -0.923104;-0.384551;0.000000;,
  -0.652733;-0.384551;-0.652733;,
  -0.000000;-0.709231;-0.704976;,
  0.498493;-0.709231;-0.498494;,
  0.704976;-0.709232;-0.000000;,
  0.498493;-0.709231;0.498494;,
  -0.000000;-0.709231;0.704976;,
  -0.498494;-0.709231;0.498494;,
  -0.704976;-0.709231;0.000000;,
  -0.498494;-0.709231;-0.498494;,
  -0.000000;-0.950593;-0.310438;,
  0.219513;-0.950594;-0.219513;,
  0.310438;-0.950594;-0.000000;,
  0.219513;-0.950594;0.219513;,
  -0.000000;-0.950593;0.310438;,
  -0.219513;-0.950593;0.219513;,
  -0.310439;-0.950593;0.000000;,
  -0.219513;-0.950593;-0.219513;,
  0.000000;-1.000000;0.000000;,
  0.000000;0.384551;0.923104;,
  -0.652732;0.384552;0.652733;,
  -0.693519;0.195093;0.693520;,
  0.000000;0.195092;0.980785;,
  -0.923103;0.384552;0.000000;,
  -0.980785;0.195093;0.000000;,
  -0.652732;0.384552;-0.652733;,
  -0.693519;0.195093;-0.693520;,
  0.000000;0.384551;-0.923104;,
  0.000000;0.195092;-0.980785;,
  0.652733;0.384551;-0.652733;,
  0.693520;0.195092;-0.693520;,
  0.923104;0.384551;0.000000;,
  0.980785;0.195091;0.000000;,
  0.652733;0.384551;0.652733;,
  0.693520;0.195092;0.693520;,
  0.000000;0.709231;0.704976;,
  -0.498493;0.709231;0.498494;,
  -0.704976;0.709232;0.000000;,
  -0.498493;0.709231;-0.498494;,
  0.000000;0.709231;-0.704976;,
  0.498494;0.709231;-0.498494;,
  0.704976;0.709231;0.000000;,
  0.498494;0.709231;0.498494;,
  0.000000;0.950593;0.310438;,
  -0.219513;0.950594;0.219513;,
  -0.310438;0.950594;0.000000;,
  -0.219513;0.950594;-0.219513;,
  0.000000;0.950593;-0.310438;,
  0.219513;0.950593;-0.219513;,
  0.310439;0.950593;0.000000;,
  0.219513;0.950593;0.219513;,
  -0.000000;1.000000;-0.000000;,
  -0.492259;0.870449;0.000000;,
  -0.298986;0.954257;-0.000000;,
  0.000000;1.000000;0.000000;,
  0.298973;0.954262;0.000000;,
  0.492232;0.870464;0.000000;,
  0.298977;-0.954260;-0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.298990;-0.954256;0.000000;,
  -0.348079;0.870449;0.348079;,
  -0.211415;0.954257;0.211415;,
  0.000000;1.000000;-0.000000;,
  0.211407;0.954260;-0.211410;,
  0.348064;0.870460;-0.348069;,
  0.211410;-0.954259;-0.211412;,
  0.000000;-1.000000;-0.000000;,
  -0.211418;-0.954256;0.211418;,
  0.000000;0.870450;0.492257;,
  0.000000;0.954258;0.298985;,
  -0.000000;1.000000;-0.000000;,
  -0.000000;0.954259;-0.298981;,
  -0.000001;0.870454;-0.492249;,
  -0.000000;-0.954258;-0.298985;,
  -0.000000;-1.000000;-0.000000;,
  0.000000;-0.954256;0.298989;,
  0.348078;0.870450;0.348078;,
  0.211414;0.954258;0.211414;,
  -0.000000;1.000000;-0.000000;,
  -0.211412;0.954259;-0.211412;,
  -0.348072;0.870454;-0.348073;,
  -0.211415;-0.954258;-0.211415;,
  -0.000000;-1.000000;-0.000000;,
  0.211417;-0.954257;0.211417;,
  0.492256;0.870451;0.000000;,
  0.298984;0.954258;0.000000;,
  -0.000001;1.000000;0.000000;,
  -0.298981;0.954259;0.000000;,
  -0.492248;0.870455;0.000000;,
  -0.298985;-0.954258;-0.000000;,
  -0.000001;-1.000000;0.000000;,
  0.298989;-0.954257;-0.000000;,
  0.348078;0.870450;-0.348078;,
  0.211414;0.954258;-0.211414;,
  -0.000000;1.000000;0.000000;,
  -0.211412;0.954259;0.211412;,
  -0.348072;0.870454;0.348073;,
  -0.211414;-0.954258;0.211415;,
  -0.000000;-1.000000;0.000000;,
  0.211417;-0.954257;-0.211417;,
  0.000000;0.870450;-0.492257;,
  0.000000;0.954258;-0.298985;,
  -0.000000;1.000000;0.000000;,
  -0.000000;0.954259;0.298981;,
  -0.000001;0.870454;0.492249;,
  -0.000000;-0.954258;0.298985;,
  -0.000000;-1.000000;0.000000;,
  0.000000;-0.954257;-0.298989;,
  -0.348079;0.870449;-0.348079;,
  -0.211415;0.954258;-0.211415;,
  0.000000;1.000000;0.000000;,
  0.211407;0.954260;0.211410;,
  0.348064;0.870460;0.348069;,
  0.211410;-0.954259;0.211412;,
  0.000000;-1.000000;0.000000;,
  -0.211418;-0.954256;-0.211418;,
  0.492240;-0.870459;-0.000000;,
  0.348069;-0.870455;-0.348074;,
  -0.492266;-0.870445;0.000000;,
  -0.348084;-0.870445;0.348084;,
  -0.000001;-0.870450;-0.492257;,
  0.000000;-0.870445;0.492265;,
  -0.348078;-0.870450;-0.348079;,
  0.348083;-0.870446;0.348083;,
  -0.492255;-0.870451;0.000000;,
  0.492263;-0.870446;-0.000000;,
  -0.348078;-0.870450;0.348079;,
  0.348083;-0.870446;-0.348083;,
  -0.000001;-0.870450;0.492257;,
  0.000000;-0.870445;-0.492265;,
  0.348069;-0.870455;0.348074;,
  -0.348084;-0.870445;-0.348084;,
  0.414693;-0.909961;-0.000001;,
  0.414654;-0.909874;-0.013840;,
  0.405750;-0.913932;-0.009785;,
  0.402061;-0.915613;-0.000000;,
  0.405750;-0.913932;0.009785;,
  0.414654;-0.909874;0.013839;,
  0.423559;-0.905816;0.009786;,
  0.427248;-0.904135;-0.000000;,
  0.423558;-0.905816;-0.009786;,
  0.414661;-0.909889;-0.012548;,
  0.406587;-0.913569;-0.008872;,
  0.403242;-0.915093;-0.000000;,
  0.406587;-0.913569;0.008873;,
  0.414661;-0.909889;0.012548;,
  0.422736;-0.906209;0.008873;,
  0.426081;-0.904685;-0.000000;,
  0.422736;-0.906210;-0.008873;,
  0.414672;-0.909913;-0.010255;,
  0.408072;-0.912921;-0.007252;,
  0.405338;-0.914167;-0.000000;,
  0.408072;-0.912921;0.007253;,
  0.414672;-0.909913;0.010256;,
  0.421272;-0.906905;0.007252;,
  0.424006;-0.905660;-0.000000;,
  0.421272;-0.906905;-0.007252;,
  -0.414654;0.909874;0.013840;,
  -0.405750;0.913932;0.009785;,
  -0.414693;0.909961;0.000001;,
  -0.402061;0.915613;0.000000;,
  -0.405750;0.913932;-0.009785;,
  -0.414654;0.909874;-0.013839;,
  -0.423559;0.905816;-0.009786;,
  -0.427248;0.904135;0.000000;,
  -0.423558;0.905816;0.009786;,
  -0.414661;0.909889;0.012548;,
  -0.406587;0.913569;0.008872;,
  -0.403242;0.915093;0.000000;,
  -0.406587;0.913569;-0.008873;,
  -0.414661;0.909889;-0.012548;,
  -0.422736;0.906209;-0.008873;,
  -0.426081;0.904685;0.000000;,
  -0.422736;0.906210;0.008873;,
  -0.414672;0.909913;0.010255;,
  -0.408072;0.912921;0.007252;,
  -0.405338;0.914167;0.000000;,
  -0.408072;0.912921;-0.007253;,
  -0.414672;0.909913;-0.010256;,
  -0.421272;0.906905;-0.007252;,
  -0.424006;0.905660;0.000000;,
  -0.421272;0.906905;0.007252;,
  -0.000000;1.000000;0.000000;,
  -0.000000;0.999990;-0.004550;,
  0.003217;0.999990;-0.003217;,
  0.004550;0.999990;0.000000;,
  0.003217;0.999990;0.003217;,
  -0.000000;0.999990;0.004550;,
  -0.003217;0.999990;0.003217;,
  -0.004550;0.999990;0.000000;,
  -0.003217;0.999990;-0.003217;,
  -0.000000;0.999594;-0.028480;,
  0.020139;0.999594;-0.020139;,
  0.028480;0.999594;0.000000;,
  0.020139;0.999594;0.020139;,
  -0.000000;0.999594;0.028480;,
  -0.020139;0.999594;0.020139;,
  -0.028481;0.999594;0.000000;,
  -0.020139;0.999594;-0.020139;,
  -0.000000;0.998251;-0.059114;,
  0.041800;0.998251;-0.041800;,
  0.059114;0.998251;0.000000;,
  0.041800;0.998251;0.041800;,
  -0.000000;0.998251;0.059114;,
  -0.041800;0.998251;0.041800;,
  -0.059114;0.998251;0.000000;,
  -0.041800;0.998251;-0.041800;,
  -0.000000;0.999162;-0.040922;,
  0.028936;0.999162;-0.028936;,
  0.040922;0.999162;0.000000;,
  0.028936;0.999162;0.028936;,
  -0.000000;0.999162;0.040922;,
  -0.028936;0.999162;0.028936;,
  -0.040921;0.999162;0.000000;,
  -0.028936;0.999162;-0.028936;;
  208;
  4;0,1,9,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,0,8,15;,
  4;8,9,17,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,8,16,23;,
  4;16,17,25,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,16,24,31;,
  3;24,25,32;,
  3;25,26,32;,
  3;26,27,32;,
  3;27,28,32;,
  3;28,29,32;,
  3;29,30,32;,
  3;30,31,32;,
  3;31,24,32;,
  4;33,34,35,36;,
  4;34,37,38,35;,
  4;37,39,40,38;,
  4;39,41,42,40;,
  4;41,43,44,42;,
  4;43,45,46,44;,
  4;45,47,48,46;,
  4;47,33,36,48;,
  4;49,50,34,33;,
  4;50,51,37,34;,
  4;51,52,39,37;,
  4;52,53,41,39;,
  4;53,54,43,41;,
  4;54,55,45,43;,
  4;55,56,47,45;,
  4;56,49,33,47;,
  4;57,58,50,49;,
  4;58,59,51,50;,
  4;59,60,52,51;,
  4;60,61,53,52;,
  4;61,62,54,53;,
  4;62,63,55,54;,
  4;63,64,56,55;,
  4;64,57,49,56;,
  3;65,58,57;,
  3;65,59,58;,
  3;65,60,59;,
  3;65,61,60;,
  3;65,62,61;,
  3;65,63,62;,
  3;65,64,63;,
  3;65,57,64;,
  4;66,67,75,74;,
  4;67,68,76,75;,
  4;68,69,77,76;,
  4;69,70,78,77;,
  4;130,71,79,131;,
  4;71,72,80,79;,
  4;72,73,81,80;,
  4;73,132,133,81;,
  4;74,75,83,82;,
  4;75,76,84,83;,
  4;76,77,85,84;,
  4;77,78,86,85;,
  4;131,79,87,134;,
  4;79,80,88,87;,
  4;80,81,89,88;,
  4;81,133,135,89;,
  4;82,83,91,90;,
  4;83,84,92,91;,
  4;84,85,93,92;,
  4;85,86,94,93;,
  4;134,87,95,136;,
  4;87,88,96,95;,
  4;88,89,97,96;,
  4;89,135,137,97;,
  4;90,91,99,98;,
  4;91,92,100,99;,
  4;92,93,101,100;,
  4;93,94,102,101;,
  4;136,95,103,138;,
  4;95,96,104,103;,
  4;96,97,105,104;,
  4;97,137,139,105;,
  4;98,99,107,106;,
  4;99,100,108,107;,
  4;100,101,109,108;,
  4;101,102,110,109;,
  4;138,103,111,140;,
  4;103,104,112,111;,
  4;104,105,113,112;,
  4;105,139,141,113;,
  4;106,107,115,114;,
  4;107,108,116,115;,
  4;108,109,117,116;,
  4;109,110,118,117;,
  4;140,111,119,142;,
  4;111,112,120,119;,
  4;112,113,121,120;,
  4;113,141,143,121;,
  4;114,115,123,122;,
  4;115,116,124,123;,
  4;116,117,125,124;,
  4;117,118,126,125;,
  4;142,119,127,144;,
  4;119,120,128,127;,
  4;120,121,129,128;,
  4;121,143,145,129;,
  4;122,123,67,66;,
  4;123,124,68,67;,
  4;124,125,69,68;,
  4;125,126,70,69;,
  4;144,127,71,130;,
  4;127,128,72,71;,
  4;128,129,73,72;,
  4;129,145,132,73;,
  3;146,148,147;,
  3;146,149,148;,
  3;146,150,149;,
  3;146,151,150;,
  3;146,152,151;,
  3;146,153,152;,
  3;146,154,153;,
  3;146,147,154;,
  4;147,148,156,155;,
  4;148,149,157,156;,
  4;149,150,158,157;,
  4;150,151,159,158;,
  4;151,152,160,159;,
  4;152,153,161,160;,
  4;153,154,162,161;,
  4;154,147,155,162;,
  4;155,156,164,163;,
  4;156,157,165,164;,
  4;157,158,166,165;,
  4;158,159,167,166;,
  4;159,160,168,167;,
  4;160,161,169,168;,
  4;161,162,170,169;,
  4;162,155,163,170;,
  3;171,172,173;,
  3;172,174,173;,
  3;174,175,173;,
  3;175,176,173;,
  3;176,177,173;,
  3;177,178,173;,
  3;178,179,173;,
  3;179,171,173;,
  4;180,181,172,171;,
  4;181,182,174,172;,
  4;182,183,175,174;,
  4;183,184,176,175;,
  4;184,185,177,176;,
  4;185,186,178,177;,
  4;186,187,179,178;,
  4;187,180,171,179;,
  4;188,189,181,180;,
  4;189,190,182,181;,
  4;190,191,183,182;,
  4;191,192,184,183;,
  4;192,193,185,184;,
  4;193,194,186,185;,
  4;194,195,187,186;,
  4;195,188,180,187;,
  3;196,198,197;,
  3;196,199,198;,
  3;196,200,199;,
  3;196,201,200;,
  3;196,202,201;,
  3;196,203,202;,
  3;196,204,203;,
  3;196,197,204;,
  4;197,198,206,205;,
  4;198,199,207,206;,
  4;199,200,208,207;,
  4;200,201,209,208;,
  4;201,202,210,209;,
  4;202,203,211,210;,
  4;203,204,212,211;,
  4;204,197,205,212;,
  4;205,206,214,213;,
  4;206,207,215,214;,
  4;207,208,216,215;,
  4;208,209,217,216;,
  4;209,210,218,217;,
  4;210,211,219,218;,
  4;211,212,220,219;,
  4;212,205,213,220;,
  4;213,214,222,221;,
  4;214,215,223,222;,
  4;215,216,224,223;,
  4;216,217,225,224;,
  4;217,218,226,225;,
  4;218,219,227,226;,
  4;219,220,228,227;,
  4;220,213,221,228;;
 }
 MeshTextureCoords {
  204;
  0.000000;0.500000;,
  0.125000;0.500000;,
  0.125000;0.625000;,
  0.000000;0.625000;,
  0.250000;0.500000;,
  0.250000;0.625000;,
  0.375000;0.500000;,
  0.375000;0.625000;,
  0.500000;0.500000;,
  0.500000;0.625000;,
  0.625000;0.500000;,
  0.625000;0.625000;,
  0.750000;0.500000;,
  0.750000;0.625000;,
  0.875000;0.500000;,
  0.875000;0.625000;,
  1.000000;0.500000;,
  1.000000;0.625000;,
  0.125000;0.750000;,
  0.000000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.125000;0.875000;,
  0.000000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.875000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;,
  0.000000;0.000000;,
  0.000000;0.125000;,
  0.125000;0.125000;,
  0.125000;0.000000;,
  0.000000;0.250000;,
  0.125000;0.250000;,
  0.000000;0.375000;,
  0.125000;0.375000;,
  0.000000;0.500000;,
  0.125000;0.500000;,
  0.000000;0.625000;,
  0.125000;0.625000;,
  0.000000;0.750000;,
  0.125000;0.750000;,
  0.000000;0.875000;,
  0.125000;0.875000;,
  0.000000;1.000000;,
  0.125000;1.000000;,
  0.250000;0.125000;,
  0.250000;0.000000;,
  0.250000;0.250000;,
  0.250000;0.375000;,
  0.250000;0.500000;,
  0.250000;0.625000;,
  0.250000;0.750000;,
  0.250000;0.875000;,
  0.250000;1.000000;,
  0.375000;0.125000;,
  0.375000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.375000;,
  0.375000;0.500000;,
  0.375000;0.625000;,
  0.375000;0.750000;,
  0.375000;0.875000;,
  0.375000;1.000000;,
  0.500000;0.125000;,
  0.500000;0.000000;,
  0.500000;0.250000;,
  0.500000;0.375000;,
  0.500000;0.500000;,
  0.500000;0.625000;,
  0.500000;0.750000;,
  0.500000;0.875000;,
  0.500000;1.000000;,
  0.625000;0.125000;,
  0.625000;0.000000;,
  0.625000;0.250000;,
  0.625000;0.375000;,
  0.625000;0.500000;,
  0.625000;0.625000;,
  0.625000;0.750000;,
  0.625000;0.875000;,
  0.625000;1.000000;,
  0.750000;0.125000;,
  0.750000;0.000000;,
  0.750000;0.250000;,
  0.750000;0.375000;,
  0.750000;0.500000;,
  0.750000;0.625000;,
  0.750000;0.750000;,
  0.750000;0.875000;,
  0.750000;1.000000;,
  0.875000;0.125000;,
  0.875000;0.000000;,
  0.875000;0.250000;,
  0.875000;0.375000;,
  0.875000;0.500000;,
  0.875000;0.625000;,
  0.875000;0.750000;,
  0.875000;0.875000;,
  0.875000;1.000000;,
  1.000000;0.125000;,
  1.000000;0.000000;,
  1.000000;0.250000;,
  1.000000;0.375000;,
  1.000000;0.500000;,
  1.000000;0.625000;,
  1.000000;0.750000;,
  1.000000;0.875000;,
  1.000000;1.000000;,
  0.062500;0.000000;,
  0.125000;0.125000;,
  0.000000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.125000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.125000;0.375000;,
  0.000000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.062500;0.000000;,
  0.125000;0.125000;,
  0.000000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.125000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.125000;0.375000;,
  0.000000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.125000;0.500000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;;
 }
}
