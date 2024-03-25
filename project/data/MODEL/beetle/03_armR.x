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
 22.50651;-8.78513;-113.32749;,
 22.50651;-4.46764;-113.32749;,
 28.06230;-4.46764;-111.82102;,
 28.06230;-8.78513;-111.82102;,
 33.61842;-4.46764;-110.31443;,
 33.61842;-8.78513;-110.31443;,
 39.17434;-4.46764;-108.80783;,
 39.17434;-8.78513;-108.80783;,
 22.50651;-0.15017;-113.32749;,
 28.06230;-0.15017;-111.82102;,
 33.61842;-0.15017;-110.31443;,
 39.17434;-0.15017;-108.80783;,
 22.50651;4.16733;-113.32749;,
 28.06230;4.16733;-111.82102;,
 33.61842;4.16733;-110.31443;,
 39.17434;4.16733;-108.80783;,
 22.50651;8.48481;-113.32749;,
 28.06230;8.48481;-111.82102;,
 33.61842;8.48481;-110.31443;,
 39.17434;8.48481;-108.80783;,
 1.37562;8.48481;-38.26464;,
 6.93140;8.48481;-36.75792;,
 12.48750;8.48481;-35.25135;,
 18.04329;8.48481;-33.74489;,
 -6.97889;8.48481;-7.45529;,
 -0.82604;0.71228;-0.44698;,
 -0.27115;0.71228;-0.29641;,
 -1.42327;8.48481;-5.94858;,
 0.28374;0.71228;-0.14603;,
 4.13365;8.48481;-4.44229;,
 0.83863;0.71228;0.00439;,
 9.68927;8.48481;-2.93561;,
 -0.82604;0.28101;-0.44698;,
 -0.27115;0.28101;-0.29641;,
 0.28374;0.28101;-0.14603;,
 0.83863;0.28101;0.00439;,
 -0.82604;-0.15017;-0.44698;,
 -0.27115;-0.15017;-0.29641;,
 0.28374;-0.15017;-0.14603;,
 0.83863;-0.15017;0.00439;,
 -0.82604;-0.58130;-0.44698;,
 -0.27115;-0.58130;-0.29641;,
 0.28374;-0.58130;-0.14603;,
 0.83863;-0.58130;0.00439;,
 -0.82604;-1.01260;-0.44698;,
 -0.27115;-1.01260;-0.29641;,
 0.28374;-1.01260;-0.14603;,
 0.83863;-1.01260;0.00439;,
 -6.97889;-8.78513;-7.45529;,
 -1.42327;-8.78513;-5.94858;,
 4.13365;-8.78513;-4.44229;,
 9.68927;-8.78513;-2.93561;,
 1.37562;-8.78513;-38.26464;,
 22.50651;-8.78513;-113.32749;,
 28.06230;-8.78513;-111.82102;,
 6.93140;-8.78513;-36.75792;,
 33.61842;-8.78513;-110.31443;,
 12.48750;-8.78513;-35.25135;,
 39.17434;-8.78513;-108.80783;,
 18.04329;-8.78513;-33.74489;,
 9.68927;-4.46764;-2.93561;,
 0.83863;-0.58130;0.00439;,
 0.83863;-1.01260;0.00439;,
 9.68927;-8.78513;-2.93561;,
 18.04329;-4.46764;-33.74489;,
 18.04329;-8.78513;-33.74489;,
 9.68927;-0.15017;-2.93561;,
 0.83863;-0.15017;0.00439;,
 18.04329;-0.15017;-33.74489;,
 9.68927;4.16733;-2.93561;,
 0.83863;0.28101;0.00439;,
 18.04329;4.16733;-33.74489;,
 9.68927;8.48481;-2.93561;,
 0.83863;0.71228;0.00439;,
 18.04329;8.48481;-33.74489;,
 -0.82604;-1.01260;-0.44698;,
 -0.82604;-0.58130;-0.44698;,
 -6.97889;-4.46764;-7.45529;,
 -6.97889;-8.78513;-7.45529;,
 1.37562;-8.78513;-38.26464;,
 1.37562;-4.46764;-38.26464;,
 -0.82604;-0.15017;-0.44698;,
 -6.97889;-0.15017;-7.45529;,
 1.37562;-0.15017;-38.26464;,
 -0.82604;0.28101;-0.44698;,
 -6.97889;4.16733;-7.45529;,
 1.37562;4.16733;-38.26464;,
 -0.82604;0.71228;-0.44698;,
 -6.97889;8.48481;-7.45529;,
 1.37562;8.48481;-38.26464;,
 48.51325;-2.87915;-186.08596;,
 48.51325;2.86570;-186.08596;,
 54.03126;2.86570;-184.48777;,
 54.03126;-2.87915;-184.48777;,
 26.03525;2.86570;-108.47200;,
 31.55331;2.86570;-106.87398;,
 26.03525;-2.87915;-108.47200;,
 31.55331;-2.87915;-106.87398;,
 48.51325;-2.87915;-186.08596;,
 54.03126;-2.87915;-184.48777;,
 31.55331;2.86570;-106.87398;,
 31.55331;-2.87915;-106.87398;,
 26.03525;-2.87915;-108.47200;,
 26.03525;2.86570;-108.47200;;
 
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
  48;
  0.261703;0.000000;-0.965148;,
  0.261706;0.000000;-0.965148;,
  0.261714;0.000000;-0.965146;,
  0.261719;0.000000;-0.965144;,
  0.261703;0.000000;-0.965149;,
  0.261706;0.000000;-0.965148;,
  0.261714;0.000000;-0.965146;,
  0.000000;1.000000;0.000000;,
  -0.443157;0.198830;0.874116;,
  -0.250585;0.288576;0.924084;,
  -0.250492;0.288597;0.924102;,
  -0.059187;0.198861;0.978239;,
  -0.529182;0.000000;0.848508;,
  -0.261729;0.000000;0.965141;,
  -0.261606;0.000000;0.965175;,
  0.027997;0.000000;0.999608;,
  -0.529182;0.000000;0.848508;,
  -0.261729;0.000000;0.965141;,
  -0.529182;0.000000;0.848508;,
  -0.443157;-0.198830;0.874116;,
  -0.250585;-0.288576;0.924084;,
  -0.250492;-0.288597;0.924103;,
  -0.059187;-0.198861;0.978239;,
  0.000000;-1.000000;-0.000000;,
  0.963878;0.000000;0.266344;,
  0.963878;0.000000;0.266344;,
  -0.963876;0.000000;-0.266350;,
  -0.963876;0.000000;-0.266350;,
  -0.526715;0.300142;0.795290;,
  -0.123780;0.881078;0.456486;,
  -0.123745;0.881089;0.456475;,
  0.052769;0.300188;0.952419;,
  0.726601;0.000000;0.687060;,
  0.052769;-0.300188;0.952419;,
  -0.123745;-0.881089;0.456475;,
  -0.123780;-0.881078;0.456486;,
  -0.526715;-0.300142;0.795290;,
  -0.974155;0.000000;0.225879;,
  -0.974155;0.000000;0.225879;,
  0.278199;0.000000;-0.960523;,
  -0.278169;0.000000;0.960532;,
  0.962585;0.000000;0.270979;,
  -0.962586;0.000000;-0.270977;,
  -0.962586;0.000000;-0.270977;,
  0.965149;0.000000;0.261703;,
  -0.965145;0.000000;-0.261716;,
  0.960529;0.000000;0.278181;,
  -0.960529;0.000000;-0.278181;;
  72;
  4;0,4,1,1;,
  4;1,1,2,2;,
  4;2,2,3,3;,
  4;4,4,1,1;,
  4;1,1,2,2;,
  4;2,2,3,3;,
  4;4,4,5,1;,
  4;1,5,6,2;,
  4;2,6,3,3;,
  4;4,0,1,5;,
  4;5,1,2,6;,
  4;6,2,3,3;,
  4;7,7,7,7;,
  4;7,7,7,7;,
  4;7,7,7,7;,
  4;28,8,9,29;,
  4;29,9,10,30;,
  4;30,10,11,31;,
  4;8,12,13,9;,
  4;9,13,14,10;,
  4;10,14,15,11;,
  4;12,16,17,13;,
  4;13,17,14,14;,
  4;14,14,15,15;,
  4;16,18,17,17;,
  4;17,17,14,14;,
  4;14,14,15,15;,
  4;18,19,20,17;,
  4;17,20,21,14;,
  4;14,21,22,15;,
  4;19,36,35,20;,
  4;20,35,34,21;,
  4;21,34,33,22;,
  4;23,23,23,23;,
  4;23,23,23,23;,
  4;23,23,23,23;,
  4;32,15,22,33;,
  4;41,41,24,25;,
  4;32,15,15,32;,
  4;41,41,25,24;,
  4;32,15,15,32;,
  4;41,41,25,25;,
  4;31,11,15,32;,
  4;41,41,25,25;,
  4;19,18,37,36;,
  4;26,26,42,42;,
  4;18,16,38,37;,
  4;26,27,43,42;,
  4;16,12,38,38;,
  4;27,27,43,43;,
  4;12,8,28,38;,
  4;27,26,42,43;,
  4;7,7,29,7;,
  4;7,29,30,7;,
  4;7,30,7,7;,
  4;25,25,44,32;,
  4;25,25,32,32;,
  4;24,25,32,32;,
  4;25,24,32,44;,
  4;34,23,23,23;,
  4;35,23,23,34;,
  4;23,23,23,35;,
  4;37,26,26,45;,
  4;38,27,26,37;,
  4;38,27,27,38;,
  4;45,26,27,38;,
  4;39,39,39,39;,
  4;7,7,7,7;,
  4;40,40,40,40;,
  4;23,23,23,23;,
  4;46,46,46,46;,
  4;47,47,47,47;;
 }
 MeshTextureCoords {
  104;
  0.375000;1.000000;,
  0.375000;0.937500;,
  0.458333;0.937500;,
  0.458333;1.000000;,
  0.541667;0.937500;,
  0.541667;1.000000;,
  0.625000;0.937500;,
  0.625000;1.000000;,
  0.375000;0.875000;,
  0.458333;0.875000;,
  0.541667;0.875000;,
  0.625000;0.875000;,
  0.375000;0.812500;,
  0.458333;0.812500;,
  0.541667;0.812500;,
  0.625000;0.812500;,
  0.375000;0.750000;,
  0.458333;0.750000;,
  0.541667;0.750000;,
  0.625000;0.750000;,
  0.375000;0.625000;,
  0.458333;0.625000;,
  0.541667;0.625000;,
  0.625000;0.625000;,
  0.375000;0.517376;,
  0.375000;0.500000;,
  0.458333;0.500000;,
  0.458333;0.517376;,
  0.541667;0.500000;,
  0.541667;0.517376;,
  0.625000;0.500000;,
  0.625000;0.517376;,
  0.375000;0.437500;,
  0.458333;0.437500;,
  0.541667;0.437500;,
  0.625000;0.437500;,
  0.375000;0.375000;,
  0.458333;0.375000;,
  0.541667;0.375000;,
  0.625000;0.375000;,
  0.375000;0.312500;,
  0.458333;0.312500;,
  0.541667;0.312500;,
  0.625000;0.312500;,
  0.375000;0.250000;,
  0.458333;0.250000;,
  0.541667;0.250000;,
  0.625000;0.250000;,
  0.375000;0.232624;,
  0.458333;0.232624;,
  0.541667;0.232624;,
  0.625000;0.232624;,
  0.375000;0.125000;,
  0.375000;0.000000;,
  0.458333;0.000000;,
  0.458333;0.125000;,
  0.541667;0.000000;,
  0.541667;0.125000;,
  0.625000;0.000000;,
  0.625000;0.125000;,
  0.857624;0.937500;,
  0.875000;0.937500;,
  0.875000;1.000000;,
  0.857624;1.000000;,
  0.750000;0.937500;,
  0.750000;1.000000;,
  0.857624;0.875000;,
  0.875000;0.875000;,
  0.750000;0.875000;,
  0.857624;0.812500;,
  0.875000;0.812500;,
  0.750000;0.812500;,
  0.857624;0.750000;,
  0.875000;0.750000;,
  0.750000;0.750000;,
  0.125000;1.000000;,
  0.125000;0.937500;,
  0.142376;0.937500;,
  0.142376;1.000000;,
  0.250000;1.000000;,
  0.250000;0.937500;,
  0.125000;0.875000;,
  0.142376;0.875000;,
  0.250000;0.875000;,
  0.125000;0.812500;,
  0.142376;0.812500;,
  0.250000;0.812500;,
  0.125000;0.750000;,
  0.142376;0.750000;,
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
