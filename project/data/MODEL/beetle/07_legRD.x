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
 104;
 -10.03594;-8.78513;113.54746;,
 -10.03594;-4.46764;113.54746;,
 -15.72286;-4.46764;112.65491;,
 -15.72286;-8.78513;112.65491;,
 -21.40993;-4.46764;111.76221;,
 -21.40993;-8.78513;111.76221;,
 -27.09684;-4.46764;110.86980;,
 -27.09684;-8.78513;110.86980;,
 -10.03594;-0.15017;113.54746;,
 -15.72286;-0.15017;112.65491;,
 -21.40993;-0.15017;111.76221;,
 -27.09684;-0.15017;110.86980;,
 -10.03594;4.16733;113.54746;,
 -15.72286;4.16733;112.65491;,
 -21.40993;4.16733;111.76221;,
 -27.09684;4.16733;110.86980;,
 -10.03594;8.48481;113.54746;,
 -15.72286;8.48481;112.65491;,
 -21.40993;8.48481;111.76221;,
 -27.09684;8.48481;110.86980;,
 2.79477;8.48481;36.62968;,
 -2.89214;8.48481;35.73702;,
 -8.57921;8.48481;34.84451;,
 -14.26613;8.48481;33.95197;,
 7.74428;8.48481;5.09374;,
 0.86488;0.71228;-1.20287;,
 0.29687;0.71228;-1.29203;,
 2.05771;8.48481;4.20110;,
 -0.27115;0.71228;-1.38105;,
 -3.63019;8.48481;3.30883;,
 -0.83901;0.71228;-1.47026;,
 -9.31677;8.48481;2.41638;,
 0.86488;0.28101;-1.20287;,
 0.29687;0.28101;-1.29203;,
 -0.27115;0.28101;-1.38105;,
 -0.83901;0.28101;-1.47026;,
 0.86488;-0.15017;-1.20287;,
 0.29687;-0.15017;-1.29203;,
 -0.27115;-0.15017;-1.38105;,
 -0.83901;-0.15017;-1.47026;,
 0.86488;-0.58130;-1.20287;,
 0.29687;-0.58130;-1.29203;,
 -0.27115;-0.58130;-1.38105;,
 -0.83901;-0.58130;-1.47026;,
 0.86488;-1.01260;-1.20287;,
 0.29687;-1.01260;-1.29203;,
 -0.27115;-1.01260;-1.38105;,
 -0.83901;-1.01260;-1.47026;,
 7.74428;-8.78513;5.09374;,
 2.05771;-8.78513;4.20110;,
 -3.63019;-8.78513;3.30883;,
 -9.31677;-8.78513;2.41638;,
 2.79477;-8.78513;36.62968;,
 -10.03594;-8.78513;113.54746;,
 -15.72286;-8.78513;112.65491;,
 -2.89214;-8.78513;35.73702;,
 -21.40993;-8.78513;111.76221;,
 -8.57921;-8.78513;34.84451;,
 -27.09684;-8.78513;110.86980;,
 -14.26613;-8.78513;33.95197;,
 -9.31677;-4.46764;2.41638;,
 -0.83901;-0.58130;-1.47026;,
 -0.83901;-1.01260;-1.47026;,
 -9.31677;-8.78513;2.41638;,
 -14.26613;-4.46764;33.95197;,
 -14.26613;-8.78513;33.95197;,
 -9.31677;-0.15017;2.41638;,
 -0.83901;-0.15017;-1.47026;,
 -14.26613;-0.15017;33.95197;,
 -9.31677;4.16733;2.41638;,
 -0.83901;0.28101;-1.47026;,
 -14.26613;4.16733;33.95197;,
 -9.31677;8.48481;2.41638;,
 -0.83901;0.71228;-1.47026;,
 -14.26613;8.48481;33.95197;,
 0.86488;-1.01260;-1.20287;,
 0.86488;-0.58130;-1.20287;,
 7.74428;-4.46764;5.09374;,
 7.74428;-8.78513;5.09374;,
 2.79477;-8.78513;36.62968;,
 2.79477;-4.46764;36.62968;,
 0.86488;-0.15017;-1.20287;,
 7.74428;-0.15017;5.09374;,
 2.79477;-0.15017;36.62968;,
 0.86488;0.28101;-1.20287;,
 7.74428;4.16733;5.09374;,
 2.79477;4.16733;36.62968;,
 0.86488;0.71228;-1.20287;,
 7.74428;8.48481;5.09374;,
 2.79477;8.48481;36.62968;,
 -21.21331;0.20170;108.94541;,
 -21.21331;5.94640;108.94541;,
 -15.60599;5.94640;110.19492;,
 -15.60599;0.20170;110.19492;,
 -38.78950;5.94640;187.81365;,
 -33.18222;5.94640;189.06314;,
 -38.78950;0.20170;187.81365;,
 -33.18222;0.20170;189.06314;,
 -21.21331;0.20170;108.94541;,
 -15.60599;0.20170;110.19492;,
 -33.18222;5.94640;189.06314;,
 -33.18222;0.20170;189.06314;,
 -38.78950;0.20170;187.81365;,
 -38.78950;5.94640;187.81365;;
 
 72;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;1,8,9,2;,
 4;2,9,10,4;,
 4;4,10,11,6;,
 4;8,12,13,9;,
 4;9,13,14,10;,
 4;10,14,15,11;,
 4;12,16,17,13;,
 4;13,17,18,14;,
 4;14,18,19,15;,
 4;16,20,21,17;,
 4;17,21,22,18;,
 4;18,22,23,19;,
 4;24,25,26,27;,
 4;27,26,28,29;,
 4;29,28,30,31;,
 4;25,32,33,26;,
 4;26,33,34,28;,
 4;28,34,35,30;,
 4;32,36,37,33;,
 4;33,37,38,34;,
 4;34,38,39,35;,
 4;36,40,41,37;,
 4;37,41,42,38;,
 4;38,42,43,39;,
 4;40,44,45,41;,
 4;41,45,46,42;,
 4;42,46,47,43;,
 4;44,48,49,45;,
 4;45,49,50,46;,
 4;46,50,51,47;,
 4;52,53,54,55;,
 4;55,54,56,57;,
 4;57,56,58,59;,
 4;60,61,62,63;,
 4;7,6,64,65;,
 4;66,67,61,60;,
 4;6,11,68,64;,
 4;69,70,67,66;,
 4;11,15,71,68;,
 4;72,73,70,69;,
 4;15,19,74,71;,
 4;75,76,77,78;,
 4;79,80,1,0;,
 4;76,81,82,77;,
 4;80,83,8,1;,
 4;81,84,85,82;,
 4;83,86,12,8;,
 4;84,87,88,85;,
 4;86,89,16,12;,
 4;20,24,27,21;,
 4;21,27,29,22;,
 4;22,29,31,23;,
 4;71,74,72,69;,
 4;68,71,69,66;,
 4;64,68,66,60;,
 4;65,64,60,63;,
 4;50,57,59,51;,
 4;49,55,57,50;,
 4;48,52,55,49;,
 4;77,80,79,78;,
 4;82,83,80,77;,
 4;85,86,83,82;,
 4;88,89,86,85;,
 4;90,91,92,93;,
 4;91,94,95,92;,
 4;94,96,97,95;,
 4;96,98,99,97;,
 4;93,92,100,101;,
 4;102,103,91,90;;
 
 MeshMaterialList {
  5;
  72;
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
   0.310588;0.203922;0.203922;1.000000;;
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
  51;
  -0.155050;0.000000;0.987907;,
  -0.155061;0.000000;0.987905;,
  -0.155049;0.000000;0.987907;,
  -0.155026;0.000000;0.987910;,
  -0.155050;0.000000;0.987907;,
  -0.155061;0.000000;0.987905;,
  -0.155026;0.000000;0.987911;,
  -0.155026;0.000000;0.987911;,
  -0.155050;0.000000;0.987907;,
  -0.155026;0.000000;0.987910;,
  0.000000;1.000000;0.000000;,
  0.345259;0.198852;-0.917199;,
  0.148374;0.288586;-0.945888;,
  0.148416;0.288599;-0.945877;,
  -0.047598;0.198873;-0.978869;,
  0.433567;0.000000;-0.901121;,
  0.154950;0.000000;-0.987922;,
  0.155013;0.000000;-0.987913;,
  -0.136589;0.000000;-0.990628;,
  0.155013;0.000000;-0.987913;,
  0.154950;0.000000;-0.987922;,
  0.345259;-0.198852;-0.917199;,
  0.148374;-0.288595;-0.945885;,
  0.148416;-0.288607;-0.945875;,
  -0.047598;-0.198873;-0.978869;,
  0.000000;-1.000000;-0.000000;,
  -0.987150;0.000000;-0.159794;,
  -0.987150;0.000000;-0.159794;,
  0.987150;0.000000;0.159796;,
  0.436947;0.300173;-0.847923;,
  0.073303;0.881083;-0.467246;,
  0.073312;0.881090;-0.467233;,
  -0.156151;0.300203;-0.941007;,
  -0.797108;0.000000;-0.603837;,
  -0.156151;-0.300203;-0.941007;,
  0.073311;-0.881094;-0.467225;,
  0.073302;-0.881088;-0.467238;,
  0.436947;-0.300174;-0.847923;,
  0.943764;0.000000;-0.330621;,
  0.943764;0.000000;-0.330621;,
  0.217501;0.000000;-0.976060;,
  -0.217499;0.000000;0.976061;,
  -0.986371;0.000000;-0.164537;,
  -0.986371;0.000000;-0.164537;,
  0.986371;0.000000;0.164537;,
  0.986371;0.000000;0.164537;,
  -0.987907;0.000000;-0.155047;,
  0.987907;0.000000;0.155050;,
  0.987907;0.000000;0.155050;,
  0.976056;0.000000;0.217520;,
  -0.976056;0.000000;-0.217519;;
  72;
  4;0,4,5,1;,
  4;1,5,2,2;,
  4;2,2,6,3;,
  4;4,4,1,5;,
  4;5,1,2,2;,
  4;2,2,6,6;,
  4;4,4,1,1;,
  4;1,1,2,2;,
  4;2,2,7,6;,
  4;4,8,1,1;,
  4;1,1,2,2;,
  4;2,2,9,7;,
  4;10,10,10,10;,
  4;10,10,10,10;,
  4;10,10,10,10;,
  4;29,11,12,30;,
  4;30,12,13,31;,
  4;31,13,14,32;,
  4;11,15,16,12;,
  4;12,16,17,13;,
  4;13,17,18,14;,
  4;15,15,16,16;,
  4;16,16,19,17;,
  4;17,19,18,18;,
  4;15,15,20,16;,
  4;16,20,17,19;,
  4;19,17,18,18;,
  4;15,21,22,20;,
  4;20,22,23,17;,
  4;17,23,24,18;,
  4;21,37,36,22;,
  4;22,36,35,23;,
  4;23,35,34,24;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;33,18,24,34;,
  4;42,43,26,26;,
  4;33,18,18,33;,
  4;43,43,26,26;,
  4;33,18,18,33;,
  4;43,43,27,26;,
  4;32,14,18,33;,
  4;43,42,26,27;,
  4;21,15,38,37;,
  4;28,28,44,44;,
  4;15,15,39,38;,
  4;28,28,44,44;,
  4;15,15,39,39;,
  4;28,28,44,44;,
  4;15,11,29,39;,
  4;28,28,45,44;,
  4;10,10,30,10;,
  4;10,30,31,10;,
  4;10,31,10,10;,
  4;27,26,46,33;,
  4;26,27,33,33;,
  4;26,26,33,33;,
  4;26,26,33,46;,
  4;35,25,25,25;,
  4;36,25,25,35;,
  4;25,25,25,36;,
  4;38,28,28,47;,
  4;39,28,28,38;,
  4;39,28,28,39;,
  4;48,28,28,39;,
  4;40,40,40,40;,
  4;10,10,10,10;,
  4;41,41,41,41;,
  4;25,25,25,25;,
  4;49,49,49,49;,
  4;50,50,50,50;;
 }
 MeshTextureCoords {
  104;
  0.375000;1.000000;,
  0.375000;0.937500;,
  0.458330;0.937500;,
  0.458330;1.000000;,
  0.541670;0.937500;,
  0.541670;1.000000;,
  0.625000;0.937500;,
  0.625000;1.000000;,
  0.375000;0.875000;,
  0.458330;0.875000;,
  0.541670;0.875000;,
  0.625000;0.875000;,
  0.375000;0.812500;,
  0.458330;0.812500;,
  0.541670;0.812500;,
  0.625000;0.812500;,
  0.375000;0.750000;,
  0.458330;0.750000;,
  0.541670;0.750000;,
  0.625000;0.750000;,
  0.375000;0.625000;,
  0.458330;0.625000;,
  0.541670;0.625000;,
  0.625000;0.625000;,
  0.375000;0.517380;,
  0.375000;0.500000;,
  0.458330;0.500000;,
  0.458330;0.517380;,
  0.541670;0.500000;,
  0.541670;0.517380;,
  0.625000;0.500000;,
  0.625000;0.517380;,
  0.375000;0.437500;,
  0.458330;0.437500;,
  0.541670;0.437500;,
  0.625000;0.437500;,
  0.375000;0.375000;,
  0.458330;0.375000;,
  0.541670;0.375000;,
  0.625000;0.375000;,
  0.375000;0.312500;,
  0.458330;0.312500;,
  0.541670;0.312500;,
  0.625000;0.312500;,
  0.375000;0.250000;,
  0.458330;0.250000;,
  0.541670;0.250000;,
  0.625000;0.250000;,
  0.375000;0.232620;,
  0.458330;0.232620;,
  0.541670;0.232620;,
  0.625000;0.232620;,
  0.375000;0.125000;,
  0.375000;0.000000;,
  0.458330;0.000000;,
  0.458330;0.125000;,
  0.541670;0.000000;,
  0.541670;0.125000;,
  0.625000;0.000000;,
  0.625000;0.125000;,
  0.857620;0.937500;,
  0.875000;0.937500;,
  0.875000;1.000000;,
  0.857620;1.000000;,
  0.750000;0.937500;,
  0.750000;1.000000;,
  0.857620;0.875000;,
  0.875000;0.875000;,
  0.750000;0.875000;,
  0.857620;0.812500;,
  0.875000;0.812500;,
  0.750000;0.812500;,
  0.857620;0.750000;,
  0.875000;0.750000;,
  0.750000;0.750000;,
  0.125000;1.000000;,
  0.125000;0.937500;,
  0.142380;0.937500;,
  0.142380;1.000000;,
  0.250000;1.000000;,
  0.250000;0.937500;,
  0.125000;0.875000;,
  0.142380;0.875000;,
  0.250000;0.875000;,
  0.125000;0.812500;,
  0.142380;0.812500;,
  0.250000;0.812500;,
  0.125000;0.750000;,
  0.142380;0.750000;,
  0.250000;0.750000;,
  0.375000;1.000000;,
  0.375000;0.750000;,
  0.625000;0.750000;,
  0.625000;1.000000;,
  0.375000;0.500000;,
  0.625000;0.500000;,
  0.375000;0.250000;,
  0.625000;0.250000;,
  0.375000;0.000000;,
  0.625000;0.000000;,
  0.875000;0.750000;,
  0.875000;1.000000;,
  0.125000;1.000000;,
  0.125000;0.750000;;
 }
}
