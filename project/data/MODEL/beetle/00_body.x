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
 231;
 -74.10150;-66.10480;-86.27457;,
 -74.10150;-95.35183;-86.27457;,
 -108.02504;-95.35183;-86.27457;,
 -108.02504;-66.10480;-86.27457;,
 -74.10150;-66.10480;-57.02766;,
 -108.02504;-66.10480;-57.02766;,
 -74.10150;-95.35183;-57.02766;,
 -108.02504;-95.35183;-57.02766;,
 -74.10150;-95.35183;-86.27457;,
 -108.02504;-95.35183;-86.27457;,
 -119.34740;-82.40512;-73.32782;,
 -119.34740;-82.40512;-69.97437;,
 -119.34740;-79.05153;-69.97437;,
 -119.34740;-79.05153;-73.32782;,
 -62.80430;-84.35458;-68.02482;,
 -62.80430;-84.35458;-75.27741;,
 -62.80430;-77.10220;-75.27741;,
 -62.80430;-77.10220;-68.02482;,
 -62.80430;-84.35458;-68.02482;,
 -62.80430;-84.35458;-75.27741;,
 -62.80430;-77.10220;-68.02482;,
 -119.34740;-79.05153;-69.97437;,
 -119.34740;-82.40512;-69.97437;,
 -119.34740;-82.40512;-73.32782;,
 74.10150;-66.10480;-86.27457;,
 108.02504;-66.10480;-86.27457;,
 108.02504;-95.35183;-86.27457;,
 74.10150;-95.35183;-86.27457;,
 74.10150;-66.10480;-57.02766;,
 108.02504;-66.10480;-57.02766;,
 74.10150;-95.35183;-57.02766;,
 108.02504;-95.35183;-57.02766;,
 74.10150;-95.35183;-86.27457;,
 108.02504;-95.35183;-86.27457;,
 119.34740;-82.40512;-73.32782;,
 119.34740;-79.05153;-73.32782;,
 119.34740;-79.05153;-69.97437;,
 119.34740;-82.40512;-69.97437;,
 62.80430;-84.35458;-68.02482;,
 62.80430;-77.10220;-68.02482;,
 62.80430;-77.10220;-75.27741;,
 62.80430;-84.35458;-75.27741;,
 62.80430;-84.35458;-68.02482;,
 62.80430;-84.35458;-75.27741;,
 62.80430;-77.10220;-68.02482;,
 119.34740;-79.05153;-69.97437;,
 119.34740;-82.40512;-69.97437;,
 119.34740;-82.40512;-73.32782;,
 60.51272;-63.74414;-127.40379;,
 43.31101;-61.57617;-131.42006;,
 35.18642;-26.51986;-151.29921;,
 69.63081;-41.15354;-127.40379;,
 0.00000;-66.00539;-131.42006;,
 0.00000;-26.51986;-151.29921;,
 -43.31101;-61.57617;-131.42006;,
 -35.18642;-26.51986;-151.29921;,
 -60.51272;-63.74414;-127.40379;,
 -69.63081;-41.15354;-127.40379;,
 35.18642;-0.12368;-151.29921;,
 69.63081;-0.12368;-127.40379;,
 0.00000;-0.12368;-151.29921;,
 -35.18642;-0.12368;-151.29921;,
 -69.63081;-0.12368;-127.40379;,
 35.18642;26.27251;-151.29921;,
 69.63081;40.90623;-127.40379;,
 0.00000;26.27251;-151.29921;,
 -35.18642;26.27251;-151.29921;,
 -69.63081;40.90623;-127.40379;,
 43.31101;71.62857;-131.42006;,
 60.28281;63.36582;-127.40379;,
 0.00000;74.63418;-131.42006;,
 -43.31101;71.62857;-131.42006;,
 -60.28281;63.36582;-127.40379;,
 53.53453;89.89439;-102.95457;,
 95.51428;71.32412;-102.95457;,
 2.03147;89.89439;-102.95457;,
 0.00000;87.34522;-102.95457;,
 -2.03147;89.89439;-102.95457;,
 -53.53453;89.89439;-102.95457;,
 -95.51428;71.32412;-102.95457;,
 53.53453;89.20139;0.51699;,
 95.51428;70.63113;0.51699;,
 2.03147;89.20139;0.51699;,
 -2.03147;89.20139;0.51699;,
 0.00000;86.65227;0.51699;,
 -95.51428;70.63113;0.51699;,
 -53.53453;89.20139;0.51699;,
 53.53453;74.29380;91.22070;,
 95.51428;60.39006;91.22070;,
 2.03147;74.29380;91.22070;,
 -2.03147;74.29380;91.22070;,
 0.00000;71.74463;91.22070;,
 -95.51428;60.39006;91.22070;,
 -53.53453;74.29380;91.22070;,
 53.53453;61.86738;143.43279;,
 74.51245;56.81588;129.64192;,
 2.03147;61.86738;143.43279;,
 -2.03147;61.86738;143.43279;,
 0.00000;59.31831;143.43279;,
 -74.51245;56.81588;129.64192;,
 -53.53453;61.86738;143.43279;,
 53.53453;40.90623;181.92447;,
 86.06710;40.90623;141.62913;,
 2.03147;40.90623;181.92447;,
 -2.03147;40.90623;181.92447;,
 0.00000;38.35715;181.92447;,
 -86.06727;40.90623;141.62913;,
 -53.53453;40.90623;181.92447;,
 53.53453;-0.12368;181.92447;,
 86.06710;-0.12368;141.62913;,
 0.00000;-0.12368;181.92447;,
 -53.53453;-0.12368;181.92447;,
 -86.06727;-0.12368;141.62913;,
 53.53453;-41.15354;181.92447;,
 86.06710;-41.15354;141.62913;,
 0.00000;-41.15354;181.92447;,
 -53.53453;-41.15354;181.92447;,
 -86.06727;-41.15354;141.62913;,
 53.53453;-88.10292;168.18284;,
 74.79647;-86.48981;141.62913;,
 0.00000;-88.10292;168.18284;,
 -53.53453;-88.10292;168.18284;,
 -74.79647;-86.48981;141.62913;,
 53.53453;-99.14260;91.22070;,
 95.79833;-86.48981;91.22070;,
 0.00000;-99.14260;91.22070;,
 -53.53453;-99.14260;91.22070;,
 -95.79833;-86.48981;91.22070;,
 53.53453;-99.14260;0.51699;,
 95.79833;-86.48981;0.51699;,
 0.00000;-99.14260;0.51699;,
 -53.53453;-99.14260;0.51699;,
 -95.79833;-86.48981;0.51699;,
 53.53453;-99.14260;-90.18684;,
 95.79833;-86.48981;-90.18684;,
 0.00000;-99.14260;-90.18684;,
 -53.53453;-99.14260;-90.18684;,
 -95.79833;-86.48981;-90.18684;,
 43.31101;-61.57617;-131.42006;,
 60.51272;-63.74414;-127.40379;,
 0.00000;-66.00539;-131.42006;,
 -43.31101;-61.57617;-131.42006;,
 -60.51272;-63.74414;-127.40379;,
 -95.79833;-86.48981;91.22070;,
 -74.79647;-86.48981;141.62913;,
 -86.06727;-41.15354;141.62913;,
 -107.06889;-41.15354;91.22070;,
 -95.79833;-86.48981;0.51699;,
 -107.06889;-41.15354;0.51699;,
 -95.79833;-86.48981;-90.18684;,
 -107.06889;-41.15354;-90.18684;,
 -86.06727;-0.12368;141.62913;,
 -107.06889;-0.12368;91.22070;,
 -107.06889;-0.12368;0.51699;,
 -107.06889;-0.12368;-90.18684;,
 -86.06727;40.90623;141.62913;,
 -107.06889;40.90623;91.22070;,
 -107.06889;40.90623;0.51699;,
 -107.06889;40.90623;-90.18684;,
 -74.51245;56.81588;129.64192;,
 -95.51428;60.39006;91.22070;,
 -95.51428;70.63113;0.51699;,
 -95.51428;71.32412;-102.95457;,
 74.79647;-86.48981;141.62913;,
 95.79833;-86.48981;91.22070;,
 107.06889;-41.15354;91.22070;,
 86.06710;-41.15354;141.62913;,
 95.79833;-86.48981;0.51699;,
 107.06889;-41.15354;0.51699;,
 95.79833;-86.48981;-90.18684;,
 107.06889;-41.15354;-90.18684;,
 107.06889;-0.12368;91.22070;,
 86.06710;-0.12368;141.62913;,
 107.06889;-0.12368;0.51699;,
 107.06889;-0.12368;-90.18684;,
 107.06889;40.90623;91.22070;,
 86.06710;40.90623;141.62913;,
 107.06889;40.90623;0.51699;,
 107.06889;40.90623;-90.18684;,
 95.51428;60.39006;91.22070;,
 74.51245;56.81588;129.64192;,
 95.51428;70.63113;0.51699;,
 95.51428;71.32412;-102.95457;,
 74.10150;-65.79043;79.45288;,
 108.02504;-65.79043;79.45288;,
 108.02504;-95.03751;79.45288;,
 74.10150;-95.03751;79.45288;,
 74.10150;-65.79043;108.69978;,
 108.02504;-65.79043;108.69978;,
 74.10150;-95.03751;108.69978;,
 108.02504;-95.03751;108.69978;,
 74.10150;-95.03751;79.45288;,
 108.02504;-95.03751;79.45288;,
 119.34740;-82.09061;92.39988;,
 119.34740;-78.73713;92.39988;,
 119.34740;-78.73713;95.75314;,
 119.34740;-82.09061;95.75314;,
 62.80430;-84.04016;97.70291;,
 62.80430;-76.78770;97.70291;,
 62.80430;-76.78770;90.45010;,
 62.80430;-84.04016;90.45010;,
 62.80430;-84.04016;97.70291;,
 62.80430;-84.04016;90.45010;,
 62.80430;-76.78770;97.70291;,
 119.34740;-78.73713;95.75314;,
 119.34740;-82.09061;95.75314;,
 119.34740;-82.09061;92.39988;,
 -74.10150;-65.79043;79.45288;,
 -74.10150;-95.03751;79.45288;,
 -108.02504;-95.03751;79.45288;,
 -108.02504;-65.79043;79.45288;,
 -74.10150;-65.79043;108.69978;,
 -108.02504;-65.79043;108.69978;,
 -74.10150;-95.03751;108.69978;,
 -108.02504;-95.03751;108.69978;,
 -74.10150;-95.03751;79.45288;,
 -108.02504;-95.03751;79.45288;,
 -119.34740;-82.09061;92.39988;,
 -119.34740;-82.09061;95.75314;,
 -119.34740;-78.73713;95.75314;,
 -119.34740;-78.73713;92.39988;,
 -62.80430;-84.04016;97.70291;,
 -62.80430;-84.04016;90.45010;,
 -62.80430;-76.78770;90.45010;,
 -62.80430;-76.78770;97.70291;,
 -62.80430;-84.04016;97.70291;,
 -62.80430;-84.04016;90.45010;,
 -62.80430;-76.78770;97.70291;,
 -119.34740;-78.73713;95.75314;,
 -119.34740;-82.09061;95.75314;,
 -119.34740;-82.09061;92.39988;;
 
 168;
 4;0,1,2,3;,
 4;4,0,3,5;,
 4;6,4,5,7;,
 4;8,6,7,9;,
 4;10,11,12,13;,
 4;14,15,16,17;,
 4;18,6,8,19;,
 4;20,4,6,18;,
 4;16,0,4,20;,
 4;15,1,0,16;,
 4;3,2,10,13;,
 4;5,3,13,21;,
 4;7,5,21,22;,
 4;9,7,22,23;,
 4;24,25,26,27;,
 4;28,29,25,24;,
 4;30,31,29,28;,
 4;32,33,31,30;,
 4;34,35,36,37;,
 4;38,39,40,41;,
 4;42,43,32,30;,
 4;44,42,30,28;,
 4;40,44,28,24;,
 4;41,40,24,27;,
 4;25,35,34,26;,
 4;29,45,35,25;,
 4;31,46,45,29;,
 4;33,47,46,31;,
 4;48,49,50,51;,
 4;49,52,53,50;,
 4;52,54,55,53;,
 4;54,56,57,55;,
 4;51,50,58,59;,
 4;50,53,60,58;,
 4;53,55,61,60;,
 4;55,57,62,61;,
 4;59,58,63,64;,
 4;58,60,65,63;,
 4;60,61,66,65;,
 4;61,62,67,66;,
 4;64,63,68,69;,
 4;63,65,70,68;,
 4;65,66,71,70;,
 4;66,67,72,71;,
 4;69,68,73,74;,
 3;73,68,75;,
 3;68,70,75;,
 3;70,76,75;,
 3;70,71,76;,
 3;76,71,77;,
 3;71,78,77;,
 4;71,72,79,78;,
 4;74,73,80,81;,
 4;73,75,82,80;,
 4;76,77,83,84;,
 4;78,79,85,86;,
 4;81,80,87,88;,
 4;80,82,89,87;,
 4;84,83,90,91;,
 4;86,85,92,93;,
 4;88,87,94,95;,
 4;87,89,96,94;,
 4;91,90,97,98;,
 4;93,92,99,100;,
 4;95,94,101,102;,
 4;94,96,103,101;,
 4;98,97,104,105;,
 4;100,99,106,107;,
 4;102,101,108,109;,
 3;101,103,108;,
 3;108,103,110;,
 3;103,105,110;,
 3;105,104,110;,
 3;110,104,111;,
 3;104,107,111;,
 4;107,106,112,111;,
 4;109,108,113,114;,
 4;108,110,115,113;,
 4;110,111,116,115;,
 4;111,112,117,116;,
 4;114,113,118,119;,
 4;113,115,120,118;,
 4;115,116,121,120;,
 4;116,117,122,121;,
 4;119,118,123,124;,
 4;118,120,125,123;,
 4;120,121,126,125;,
 4;121,122,127,126;,
 4;124,123,128,129;,
 4;123,125,130,128;,
 4;125,126,131,130;,
 4;126,127,132,131;,
 4;129,128,133,134;,
 4;128,130,135,133;,
 4;130,131,136,135;,
 4;131,132,137,136;,
 4;134,133,138,139;,
 4;133,135,140,138;,
 4;135,136,141,140;,
 4;136,137,142,141;,
 4;143,144,145,146;,
 4;147,143,146,148;,
 4;149,147,148,150;,
 4;56,149,150,57;,
 4;146,145,151,152;,
 4;148,146,152,153;,
 4;150,148,153,154;,
 4;57,150,154,62;,
 4;152,151,155,156;,
 4;153,152,156,157;,
 4;154,153,157,158;,
 4;62,154,158,67;,
 4;156,155,159,160;,
 4;157,156,160,161;,
 4;158,157,161,162;,
 4;67,158,162,72;,
 4;163,164,165,166;,
 4;164,167,168,165;,
 4;167,169,170,168;,
 4;169,48,51,170;,
 4;166,165,171,172;,
 4;165,168,173,171;,
 4;168,170,174,173;,
 4;170,51,59,174;,
 4;172,171,175,176;,
 4;171,173,177,175;,
 4;173,174,178,177;,
 4;174,59,64,178;,
 4;176,175,179,180;,
 4;175,177,181,179;,
 4;177,178,182,181;,
 4;178,64,69,182;,
 4;82,75,76,84;,
 4;89,82,84,91;,
 4;96,89,91,98;,
 4;103,96,98,105;,
 4;83,77,78,86;,
 4;90,83,86,93;,
 4;97,90,93,100;,
 4;104,97,100,107;,
 4;183,184,185,186;,
 4;187,188,184,183;,
 4;189,190,188,187;,
 4;191,192,190,189;,
 4;193,194,195,196;,
 4;197,198,199,200;,
 4;201,202,191,189;,
 4;203,201,189,187;,
 4;199,203,187,183;,
 4;200,199,183,186;,
 4;184,194,193,185;,
 4;188,204,194,184;,
 4;190,205,204,188;,
 4;192,206,205,190;,
 4;207,208,209,210;,
 4;211,207,210,212;,
 4;213,211,212,214;,
 4;215,213,214,216;,
 4;217,218,219,220;,
 4;221,222,223,224;,
 4;225,213,215,226;,
 4;227,211,213,225;,
 4;223,207,211,227;,
 4;222,208,207,223;,
 4;210,209,217,220;,
 4;212,210,220,228;,
 4;214,212,228,229;,
 4;216,214,229,230;;
 
 MeshMaterialList {
  5;
  168;
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
  0;;
  Material {
   0.048000;0.032000;0.032000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "ac2_01.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "ac2_02.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "arms_01.png";
   }
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  187;
  0.920958;-0.275533;-0.275534;,
  -0.937380;-0.246291;-0.246291;,
  0.920958;0.275531;-0.275533;,
  -0.937380;0.246291;-0.246291;,
  0.920958;0.275531;0.275533;,
  -0.937380;0.246291;0.246292;,
  0.920958;-0.275533;0.275534;,
  -0.937380;-0.246292;0.246292;,
  0.376459;0.000000;-0.926434;,
  0.376459;0.000000;0.926434;,
  0.376463;0.926432;0.000000;,
  -0.413337;0.000000;-0.910578;,
  -0.413336;0.910578;0.000000;,
  -0.413336;0.000000;0.910579;,
  -0.920958;-0.275533;-0.275534;,
  0.937380;-0.246291;-0.246291;,
  -0.920958;0.275531;-0.275533;,
  0.937380;0.246291;-0.246291;,
  -0.920958;0.275531;0.275533;,
  0.937380;0.246291;0.246292;,
  -0.920958;-0.275533;0.275534;,
  0.937380;-0.246292;0.246292;,
  -0.376459;0.000000;-0.926434;,
  -0.376459;0.000000;0.926434;,
  -0.376463;0.926432;0.000000;,
  0.413337;0.000000;-0.910578;,
  0.413336;0.910578;0.000000;,
  0.413336;0.000000;0.910579;,
  0.398081;-0.416945;-0.817122;,
  0.137567;-0.569400;-0.810469;,
  0.000000;-0.624446;-0.781068;,
  -0.137567;-0.569400;-0.810469;,
  -0.398081;-0.416945;-0.817122;,
  0.576077;-0.114058;-0.809398;,
  0.241113;-0.184540;-0.952791;,
  0.000000;-0.240637;-0.970615;,
  -0.241113;-0.184540;-0.952791;,
  -0.576077;-0.114058;-0.809398;,
  0.639981;0.000000;-0.768390;,
  0.298629;0.000000;-0.954369;,
  0.000000;0.000000;-1.000000;,
  -0.298629;0.000000;-0.954369;,
  -0.639981;0.000000;-0.768390;,
  0.589485;0.090895;-0.802649;,
  0.266994;0.171638;-0.948290;,
  0.000000;0.198303;-0.980141;,
  -0.266994;0.171638;-0.948290;,
  -0.589485;0.090895;-0.802649;,
  0.499571;0.359853;-0.787994;,
  0.190543;0.652480;-0.733459;,
  -0.170893;0.716152;-0.676699;,
  -0.085654;0.629669;-0.772127;,
  -0.499571;0.359853;-0.787994;,
  0.687306;0.599700;-0.409842;,
  0.212789;0.926053;-0.311682;,
  -0.581297;0.776269;-0.243928;,
  -0.212789;0.926053;-0.311682;,
  -0.687306;0.599700;-0.409842;,
  0.700639;0.712276;0.042036;,
  0.194555;0.977835;0.077371;,
  0.780938;0.622348;0.053099;,
  -0.194555;0.977835;0.077371;,
  -0.700639;0.712276;0.042036;,
  0.616267;0.761358;0.201367;,
  0.175247;0.965611;0.192051;,
  0.775971;0.618392;0.124342;,
  -0.175247;0.965611;0.192051;,
  -0.616267;0.761359;0.201367;,
  0.533459;0.764714;0.361432;,
  0.215981;0.907418;0.360478;,
  0.760134;0.605780;0.235005;,
  -0.215980;0.907418;0.360478;,
  -0.533458;0.764716;0.361431;,
  0.791493;0.356970;0.496096;,
  0.259752;0.837989;0.479900;,
  0.740544;0.590174;0.321387;,
  -0.495358;0.626378;0.601889;,
  -0.791492;0.356971;0.496096;,
  0.859255;0.000000;0.511548;,
  0.343375;0.000000;0.939198;,
  0.000000;0.000000;1.000000;,
  -0.343374;0.000000;0.939199;,
  -0.859255;0.000000;0.511548;,
  0.855283;-0.104078;0.507601;,
  0.431440;-0.130346;0.892675;,
  0.000000;-0.141888;0.989883;,
  -0.431440;-0.130347;0.892676;,
  -0.855283;-0.104079;0.507601;,
  0.842032;-0.206955;0.498148;,
  0.424375;-0.258016;0.867948;,
  0.000000;-0.280905;0.959736;,
  -0.424374;-0.258017;0.867948;,
  -0.842032;-0.206956;0.498148;,
  0.276400;-0.958894;0.064232;,
  0.139596;-0.987845;0.068372;,
  0.000000;-0.997464;0.071175;,
  -0.139596;-0.987845;0.068372;,
  -0.276400;-0.958894;0.064232;,
  0.723605;-0.690215;-0.000000;,
  0.144930;-0.989442;-0.000000;,
  0.000000;-1.000000;0.000000;,
  -0.144930;-0.989442;0.000000;,
  -0.723605;-0.690215;0.000000;,
  0.419699;-0.732694;-0.535735;,
  0.126172;-0.926626;-0.354181;,
  0.000000;-0.938048;-0.346506;,
  -0.126172;-0.926626;-0.354181;,
  -0.419699;-0.732694;-0.535735;,
  -0.973536;-0.119322;0.194907;,
  -0.992588;-0.121529;0.000000;,
  -0.911876;-0.123969;-0.391297;,
  -0.980584;0.000000;0.196100;,
  -1.000000;0.000000;0.000000;,
  -0.923312;0.000000;-0.384051;,
  -0.940490;0.269928;0.206438;,
  -0.979048;0.203555;0.005544;,
  -0.902817;0.125796;-0.411214;,
  0.973536;-0.119322;0.194908;,
  0.992588;-0.121529;-0.000000;,
  0.911876;-0.123969;-0.391297;,
  0.980584;0.000000;0.196102;,
  1.000000;0.000000;0.000000;,
  0.923312;0.000000;-0.384051;,
  0.940490;0.269928;0.206439;,
  0.979048;0.203555;0.005544;,
  0.902817;0.125796;-0.411214;,
  -0.335283;0.896601;-0.289294;,
  -0.433640;0.897839;0.076428;,
  -0.429749;0.885247;0.177913;,
  -0.419464;0.847093;0.326317;,
  -0.404964;0.802989;0.437278;,
  0.361301;0.838229;-0.408453;,
  0.433640;0.897839;0.076428;,
  0.429749;0.885247;0.177913;,
  0.419464;0.847093;0.326317;,
  0.404964;0.802989;0.437278;,
  -0.920958;-0.275531;-0.275533;,
  0.937382;-0.246289;-0.246288;,
  -0.920958;0.275532;-0.275533;,
  0.937381;0.246291;-0.246288;,
  -0.920956;0.275533;0.275538;,
  0.937380;0.246292;0.246292;,
  -0.920957;-0.275532;0.275538;,
  0.937380;-0.246289;0.246292;,
  -0.376460;0.000000;-0.926433;,
  -0.376452;0.000000;0.926436;,
  -0.376461;0.926433;0.000000;,
  0.413341;0.000000;-0.910576;,
  0.413336;0.910579;0.000000;,
  0.413335;0.000000;0.910579;,
  0.920958;-0.275531;-0.275533;,
  -0.937382;-0.246289;-0.246288;,
  0.920958;0.275532;-0.275533;,
  -0.937381;0.246291;-0.246288;,
  0.920956;0.275533;0.275538;,
  -0.937380;0.246292;0.246292;,
  0.920957;-0.275532;0.275538;,
  -0.937380;-0.246289;0.246292;,
  0.376460;0.000000;-0.926433;,
  0.376452;0.000000;0.926436;,
  0.376461;0.926433;0.000000;,
  -0.413341;0.000000;-0.910576;,
  -0.413336;0.910579;0.000000;,
  -0.413335;0.000000;0.910579;,
  0.376460;-0.926433;-0.000000;,
  -0.413336;-0.910579;0.000000;,
  -0.376460;-0.926433;0.000000;,
  0.413336;-0.910579;-0.000000;,
  0.688373;0.548579;-0.474556;,
  0.431174;0.000000;0.902269;,
  0.264830;-0.955736;0.128192;,
  0.133614;-0.981614;0.136314;,
  0.000000;-0.989868;0.141990;,
  -0.133614;-0.981614;0.136314;,
  -0.264830;-0.955736;0.128192;,
  -0.952607;-0.236819;0.190935;,
  -0.970462;-0.241256;0.000000;,
  0.952607;-0.236818;0.190936;,
  0.970462;-0.241256;-0.000000;,
  -0.780938;0.622348;0.053099;,
  -0.775971;0.618392;0.124342;,
  -0.760134;0.605780;0.235005;,
  -0.740544;0.590174;0.321387;,
  -0.376462;-0.926432;0.000000;,
  0.413339;-0.910577;-0.000000;,
  0.376462;-0.926432;-0.000000;,
  -0.413339;-0.910577;0.000000;;
  168;
  4;8,8,11,11;,
  4;10,10,12,12;,
  4;9,9,13,13;,
  4;164,164,165,165;,
  4;1,7,5,3;,
  4;6,0,2,4;,
  4;6,164,164,0;,
  4;4,9,9,6;,
  4;2,10,10,4;,
  4;0,8,8,2;,
  4;11,11,1,3;,
  4;12,12,3,5;,
  4;13,13,5,7;,
  4;165,165,7,1;,
  4;22,25,25,22;,
  4;24,26,26,24;,
  4;23,27,27,23;,
  4;166,167,167,166;,
  4;15,17,19,21;,
  4;20,18,16,14;,
  4;20,14,166,166;,
  4;18,20,23,23;,
  4;16,18,24,24;,
  4;14,16,22,22;,
  4;25,17,15,25;,
  4;26,19,17,26;,
  4;27,21,19,27;,
  4;167,15,21,167;,
  4;28,29,34,33;,
  4;29,30,35,34;,
  4;30,31,36,35;,
  4;31,32,37,36;,
  4;33,34,39,38;,
  4;34,35,40,39;,
  4;35,36,41,40;,
  4;36,37,42,41;,
  4;38,39,44,43;,
  4;39,40,45,44;,
  4;40,41,46,45;,
  4;41,42,47,46;,
  4;43,44,49,48;,
  4;44,45,50,49;,
  4;45,46,51,50;,
  4;46,47,52,51;,
  4;48,49,54,53;,
  3;54,49,126;,
  3;49,50,126;,
  3;50,55,126;,
  3;50,51,55;,
  3;168,51,131;,
  3;51,56,131;,
  4;51,52,57,56;,
  4;53,54,59,58;,
  4;54,126,127,59;,
  4;168,131,132,60;,
  4;56,57,62,61;,
  4;58,59,64,63;,
  4;59,127,128,64;,
  4;60,132,133,65;,
  4;61,62,67,66;,
  4;63,64,69,68;,
  4;64,128,129,69;,
  4;65,133,134,70;,
  4;66,67,72,71;,
  4;68,69,74,73;,
  4;69,129,130,74;,
  4;70,134,135,75;,
  4;71,72,77,76;,
  4;73,169,79,78;,
  3;169,80,79;,
  3;79,80,80;,
  3;80,80,80;,
  3;80,80,80;,
  3;80,80,81;,
  3;80,80,81;,
  4;76,77,82,81;,
  4;78,79,84,83;,
  4;79,80,85,84;,
  4;80,81,86,85;,
  4;81,82,87,86;,
  4;83,84,89,88;,
  4;84,85,90,89;,
  4;85,86,91,90;,
  4;86,87,92,91;,
  4;170,171,94,93;,
  4;171,172,95,94;,
  4;172,173,96,95;,
  4;173,174,97,96;,
  4;93,94,99,98;,
  4;94,95,100,99;,
  4;95,96,101,100;,
  4;96,97,102,101;,
  4;98,99,104,103;,
  4;99,100,105,104;,
  4;100,101,106,105;,
  4;101,102,107,106;,
  4;103,104,29,28;,
  4;104,105,30,29;,
  4;105,106,31,30;,
  4;106,107,32,31;,
  4;175,92,87,108;,
  4;102,175,108,109;,
  4;176,102,109,110;,
  4;32,107,110,37;,
  4;108,87,82,111;,
  4;109,108,111,112;,
  4;110,109,112,113;,
  4;37,110,113,42;,
  4;111,82,77,114;,
  4;112,111,114,115;,
  4;113,112,115,116;,
  4;42,113,116,47;,
  4;114,77,72,67;,
  4;115,114,67,62;,
  4;116,115,62,57;,
  4;47,116,57,52;,
  4;88,177,117,83;,
  4;177,98,118,117;,
  4;98,178,119,118;,
  4;103,28,33,119;,
  4;83,117,120,78;,
  4;117,118,121,120;,
  4;118,119,122,121;,
  4;119,33,38,122;,
  4;78,120,123,73;,
  4;120,121,124,123;,
  4;121,122,125,124;,
  4;122,38,43,125;,
  4;73,123,63,68;,
  4;123,124,58,63;,
  4;124,125,53,58;,
  4;125,43,48,53;,
  4;127,126,55,179;,
  4;128,127,179,180;,
  4;129,128,180,181;,
  4;130,129,181,182;,
  4;132,131,56,61;,
  4;133,132,61,66;,
  4;134,133,66,71;,
  4;135,134,71,76;,
  4;144,147,147,144;,
  4;146,148,148,146;,
  4;145,149,149,145;,
  4;183,184,184,183;,
  4;137,139,141,143;,
  4;142,140,138,136;,
  4;142,136,183,183;,
  4;140,142,145,145;,
  4;138,140,146,146;,
  4;136,138,144,144;,
  4;147,139,137,147;,
  4;148,141,139,148;,
  4;149,143,141,149;,
  4;184,137,143,184;,
  4;158,158,161,161;,
  4;160,160,162,162;,
  4;159,159,163,163;,
  4;185,185,186,186;,
  4;151,157,155,153;,
  4;156,150,152,154;,
  4;156,185,185,150;,
  4;154,159,159,156;,
  4;152,160,160,154;,
  4;150,158,158,152;,
  4;161,161,151,153;,
  4;162,162,153,155;,
  4;163,163,155,157;,
  4;186,186,157,151;;
 }
 MeshTextureCoords {
  231;
  0.400766;0.750000;,
  0.400766;1.000000;,
  0.599083;1.000000;,
  0.599083;0.750000;,
  0.400766;0.500000;,
  0.599083;0.500000;,
  0.400766;0.250000;,
  0.599083;0.250000;,
  0.400766;0.000000;,
  0.599083;0.000000;,
  0.625000;1.000000;,
  0.875000;1.000000;,
  0.875000;0.750000;,
  0.625000;0.750000;,
  0.125000;1.000000;,
  0.375000;1.000000;,
  0.375000;0.750000;,
  0.125000;0.750000;,
  0.375000;0.250000;,
  0.375000;0.000000;,
  0.375000;0.500000;,
  0.625000;0.500000;,
  0.625000;0.250000;,
  0.625000;0.000000;,
  0.400766;0.750000;,
  0.599083;0.750000;,
  0.599083;1.000000;,
  0.400766;1.000000;,
  0.400766;0.500000;,
  0.599083;0.500000;,
  0.400766;0.250000;,
  0.599083;0.250000;,
  0.400766;0.000000;,
  0.599083;0.000000;,
  0.625000;1.000000;,
  0.625000;0.750000;,
  0.875000;0.750000;,
  0.875000;1.000000;,
  0.125000;1.000000;,
  0.125000;0.750000;,
  0.375000;0.750000;,
  0.375000;1.000000;,
  0.375000;0.250000;,
  0.375000;0.000000;,
  0.375000;0.500000;,
  0.625000;0.500000;,
  0.625000;0.250000;,
  0.625000;0.000000;,
  0.375000;1.000000;,
  0.437500;1.000000;,
  0.437500;0.937500;,
  0.375000;0.937500;,
  0.500000;1.000000;,
  0.500000;0.937500;,
  0.562500;1.000000;,
  0.562500;0.937500;,
  0.625000;1.000000;,
  0.625000;0.937500;,
  0.437500;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.562500;0.875000;,
  0.625000;0.875000;,
  0.437500;0.812500;,
  0.375000;0.812500;,
  0.500000;0.812500;,
  0.562500;0.812500;,
  0.625000;0.812500;,
  0.437500;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.562500;0.750000;,
  0.625000;0.750000;,
  0.437500;0.687500;,
  0.375000;0.687500;,
  0.468750;0.687500;,
  0.500000;0.687500;,
  0.531250;0.687500;,
  0.562500;0.687500;,
  0.625000;0.687500;,
  0.437500;0.625000;,
  0.375000;0.625000;,
  0.468750;0.625000;,
  0.531250;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.562500;0.625000;,
  0.437500;0.562500;,
  0.375000;0.562500;,
  0.468750;0.562500;,
  0.531250;0.562500;,
  0.500000;0.562500;,
  0.625000;0.562500;,
  0.562500;0.562500;,
  0.437500;0.500000;,
  0.375000;0.500000;,
  0.468750;0.500000;,
  0.531250;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.562500;0.500000;,
  0.437500;0.437500;,
  0.375000;0.437500;,
  0.468750;0.437500;,
  0.531250;0.437500;,
  0.500000;0.437500;,
  0.625000;0.437500;,
  0.562500;0.437500;,
  0.437500;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.562500;0.375000;,
  0.625000;0.375000;,
  0.437500;0.312500;,
  0.375000;0.312500;,
  0.500000;0.312500;,
  0.562500;0.312500;,
  0.625000;0.312500;,
  0.437500;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.562500;0.250000;,
  0.625000;0.250000;,
  0.437500;0.187500;,
  0.375000;0.187500;,
  0.500000;0.187500;,
  0.562500;0.187500;,
  0.625000;0.187500;,
  0.437500;0.125000;,
  0.375000;0.125000;,
  0.500000;0.125000;,
  0.562500;0.125000;,
  0.625000;0.125000;,
  0.437500;0.062500;,
  0.375000;0.062500;,
  0.500000;0.062500;,
  0.562500;0.062500;,
  0.625000;0.062500;,
  0.437500;0.000000;,
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.562500;0.000000;,
  0.625000;0.000000;,
  0.812500;1.000000;,
  0.875000;1.000000;,
  0.875000;0.937500;,
  0.812500;0.937500;,
  0.750000;1.000000;,
  0.750000;0.937500;,
  0.687500;1.000000;,
  0.687500;0.937500;,
  0.875000;0.875000;,
  0.812500;0.875000;,
  0.750000;0.875000;,
  0.687500;0.875000;,
  0.875000;0.812500;,
  0.812500;0.812500;,
  0.750000;0.812500;,
  0.687500;0.812500;,
  0.875000;0.750000;,
  0.812500;0.750000;,
  0.750000;0.750000;,
  0.687500;0.750000;,
  0.125000;1.000000;,
  0.187500;1.000000;,
  0.187500;0.937500;,
  0.125000;0.937500;,
  0.250000;1.000000;,
  0.250000;0.937500;,
  0.312500;1.000000;,
  0.312500;0.937500;,
  0.187500;0.875000;,
  0.125000;0.875000;,
  0.250000;0.875000;,
  0.312500;0.875000;,
  0.187500;0.812500;,
  0.125000;0.812500;,
  0.250000;0.812500;,
  0.312500;0.812500;,
  0.187500;0.750000;,
  0.125000;0.750000;,
  0.250000;0.750000;,
  0.312500;0.750000;,
  0.400766;0.750000;,
  0.599083;0.750000;,
  0.599083;1.000000;,
  0.400766;1.000000;,
  0.400766;0.500000;,
  0.599083;0.500000;,
  0.400766;0.250000;,
  0.599083;0.250000;,
  0.400766;0.000000;,
  0.599083;0.000000;,
  0.625000;1.000000;,
  0.625000;0.750000;,
  0.875000;0.750000;,
  0.875000;1.000000;,
  0.125000;1.000000;,
  0.125000;0.750000;,
  0.375000;0.750000;,
  0.375000;1.000000;,
  0.375000;0.250000;,
  0.375000;0.000000;,
  0.375000;0.500000;,
  0.625000;0.500000;,
  0.625000;0.250000;,
  0.625000;0.000000;,
  0.400766;0.750000;,
  0.400766;1.000000;,
  0.599083;1.000000;,
  0.599083;0.750000;,
  0.400766;0.500000;,
  0.599083;0.500000;,
  0.400766;0.250000;,
  0.599083;0.250000;,
  0.400766;0.000000;,
  0.599083;0.000000;,
  0.625000;1.000000;,
  0.875000;1.000000;,
  0.875000;0.750000;,
  0.625000;0.750000;,
  0.125000;1.000000;,
  0.375000;1.000000;,
  0.375000;0.750000;,
  0.125000;0.750000;,
  0.375000;0.250000;,
  0.375000;0.000000;,
  0.375000;0.500000;,
  0.625000;0.500000;,
  0.625000;0.250000;,
  0.625000;0.000000;;
 }
}