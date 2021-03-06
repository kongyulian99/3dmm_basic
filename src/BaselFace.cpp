#include "utility.h"
#include <stdio.h>
#include <iostream>
#include "BaselFace.h"

int BaselFace::BaselFace_faces_w = 0;
int BaselFace::BaselFace_faces_h = 0;
int* BaselFace::BaselFace_faces = 0;
int BaselFace::BaselFace_shapeMU_w = 0;
int BaselFace::BaselFace_shapeMU_h = 0;
float* BaselFace::BaselFace_shapeMU = 0;
int BaselFace::BaselFace_shapePC_w = 0;
int BaselFace::BaselFace_shapePC_h = 0;
float* BaselFace::BaselFace_shapePC = 0;
int BaselFace::BaselFace_shapeEV_w = 0;
int BaselFace::BaselFace_shapeEV_h = 0;
float* BaselFace::BaselFace_shapeEV = 0;
int BaselFace::BaselFace_texMU_w = 0;
int BaselFace::BaselFace_texMU_h = 0;
float* BaselFace::BaselFace_texMU = 0;
int BaselFace::BaselFace_texPC_w = 0;
int BaselFace::BaselFace_texPC_h = 0;
float* BaselFace::BaselFace_texPC = 0;
int BaselFace::BaselFace_texEV_w = 0;
int BaselFace::BaselFace_texEV_h = 0;
float* BaselFace::BaselFace_texEV = 0;
int BaselFace::BaselFace_segbin_w = 0;
int BaselFace::BaselFace_segbin_h = 0;
char* BaselFace::BaselFace_segbin = 0;
int BaselFace::BaselFace_wparts_w = 0;
int BaselFace::BaselFace_wparts_h = 0;
float* BaselFace::BaselFace_wparts = 0;
int BaselFace::BaselFace_lmInd_w = 0;
int BaselFace::BaselFace_lmInd_h = 0;
int* BaselFace::BaselFace_lmInd = 0;
int BaselFace::BaselFace_lmInd2_w = 0;
int BaselFace::BaselFace_lmInd2_h = 0;
int* BaselFace::BaselFace_lmInd2 = 0;
int BaselFace::BaselFace_keepV_w = 0;
int BaselFace::BaselFace_keepV_h = 0;
char* BaselFace::BaselFace_keepV = 0;
int BaselFace::BaselFace_faces_extra_w = 0;
int BaselFace::BaselFace_faces_extra_h = 0;
int* BaselFace::BaselFace_faces_extra = 0;
int BaselFace::BaselFace_mid_w = 0;
int BaselFace::BaselFace_mid_h = 0;
char* BaselFace::BaselFace_mid = 0;
int BaselFace::BaselFace_texEdges_w = 0;
int BaselFace::BaselFace_texEdges_h = 0;
int* BaselFace::BaselFace_texEdges = 0;
int BaselFace::BaselFace_canContour_w = 0;
int BaselFace::BaselFace_canContour_h = 0;
char* BaselFace::BaselFace_canContour = 0;
int BaselFace::BaselFace_keepVT_w = 0;
int BaselFace::BaselFace_keepVT_h = 0;
int* BaselFace::BaselFace_keepVT = 0;
int BaselFace::BaselFace_pair_w = 0;
int BaselFace::BaselFace_pair_h = 0;
int* BaselFace::BaselFace_pair = 0;
int BaselFace::BaselFace_pairKeepVT_w = 0;
int BaselFace::BaselFace_pairKeepVT_h = 0;
int* BaselFace::BaselFace_pairKeepVT = 0;
int BaselFace::BaselFace_vseg_bin_w = 0;
int BaselFace::BaselFace_vseg_bin_h = 0;
char* BaselFace::BaselFace_vseg_bin = 0;
int BaselFace::BaselFace_indPX_w = 0;
int BaselFace::BaselFace_indPX_h = 0;
int* BaselFace::BaselFace_indPX = 0;
int BaselFace::BaselFace_indNX_w = 0;
int BaselFace::BaselFace_indNX_h = 0;
int* BaselFace::BaselFace_indNX = 0;
int BaselFace::BaselFace_symSPC_w = 0;
int BaselFace::BaselFace_symSPC_h = 0;
float* BaselFace::BaselFace_symSPC = 0;
int BaselFace::BaselFace_symTPC_w = 0;
int BaselFace::BaselFace_symTPC_h = 0;
float* BaselFace::BaselFace_symTPC = 0;
int BaselFace::BaselFace_expMU_w = 0;
int BaselFace::BaselFace_expMU_h = 0;
float* BaselFace::BaselFace_expMU = 0;
int BaselFace::BaselFace_expEV_w = 0;
int BaselFace::BaselFace_expEV_h = 0;
float* BaselFace::BaselFace_expEV = 0;
int BaselFace::BaselFace_expPC_w = 0;
int BaselFace::BaselFace_expPC_h = 0;
float* BaselFace::BaselFace_expPC = 0;
int BaselFace::BaselFace_expPCFlip_w = 0;
int BaselFace::BaselFace_expPCFlip_h = 0;
float* BaselFace::BaselFace_expPCFlip = 0;
bool BaselFace::load_BaselFace_data(char* fname){
	if (BaselFace_faces != 0) return true;
	FILE* file = fopen(fname,"rb");
	if (file == 0) return false;

	fread ( &BaselFace_faces_h, sizeof(int), 1, file );
	fread ( &BaselFace_faces_w, sizeof(int), 1, file );
	BaselFace_faces = new int[BaselFace_faces_h*BaselFace_faces_w];
	fread ( BaselFace_faces, sizeof(int), BaselFace_faces_h * BaselFace_faces_w, file );
	fread ( &BaselFace_shapeMU_h, sizeof(int), 1, file );
	fread ( &BaselFace_shapeMU_w, sizeof(int), 1, file );
	BaselFace_shapeMU = new float[BaselFace_shapeMU_h*BaselFace_shapeMU_w];
	fread ( BaselFace_shapeMU, sizeof(float), BaselFace_shapeMU_h * BaselFace_shapeMU_w, file );
	fread ( &BaselFace_shapePC_h, sizeof(int), 1, file );
	fread ( &BaselFace_shapePC_w, sizeof(int), 1, file );
	BaselFace_shapePC = new float[BaselFace_shapePC_h*BaselFace_shapePC_w];
	fread ( BaselFace_shapePC, sizeof(float), BaselFace_shapePC_h * BaselFace_shapePC_w, file );
	fread ( &BaselFace_shapeEV_h, sizeof(int), 1, file );
	fread ( &BaselFace_shapeEV_w, sizeof(int), 1, file );
	BaselFace_shapeEV = new float[BaselFace_shapeEV_h*BaselFace_shapeEV_w];
	fread ( BaselFace_shapeEV, sizeof(float), BaselFace_shapeEV_h * BaselFace_shapeEV_w, file );
	fread ( &BaselFace_texMU_h, sizeof(int), 1, file );
	fread ( &BaselFace_texMU_w, sizeof(int), 1, file );
	BaselFace_texMU = new float[BaselFace_texMU_h*BaselFace_texMU_w];
	fread ( BaselFace_texMU, sizeof(float), BaselFace_texMU_h * BaselFace_texMU_w, file );
	fread ( &BaselFace_texPC_h, sizeof(int), 1, file );
	fread ( &BaselFace_texPC_w, sizeof(int), 1, file );
	BaselFace_texPC = new float[BaselFace_texPC_h*BaselFace_texPC_w];
	fread ( BaselFace_texPC, sizeof(float), BaselFace_texPC_h * BaselFace_texPC_w, file );
	fread ( &BaselFace_texEV_h, sizeof(int), 1, file );
	fread ( &BaselFace_texEV_w, sizeof(int), 1, file );
	BaselFace_texEV = new float[BaselFace_texEV_h*BaselFace_texEV_w];
	fread ( BaselFace_texEV, sizeof(float), BaselFace_texEV_h * BaselFace_texEV_w, file );
	fread ( &BaselFace_segbin_h, sizeof(int), 1, file );
	fread ( &BaselFace_segbin_w, sizeof(int), 1, file );
	BaselFace_segbin = new char[BaselFace_segbin_h*BaselFace_segbin_w];
	fread ( BaselFace_segbin, sizeof(char), BaselFace_segbin_h * BaselFace_segbin_w, file );
	fread ( &BaselFace_wparts_h, sizeof(int), 1, file );
	fread ( &BaselFace_wparts_w, sizeof(int), 1, file );
	BaselFace_wparts = new float[BaselFace_wparts_h*BaselFace_wparts_w];
	fread ( BaselFace_wparts, sizeof(float), BaselFace_wparts_h * BaselFace_wparts_w, file );
	fread ( &BaselFace_lmInd_h, sizeof(int), 1, file );
	fread ( &BaselFace_lmInd_w, sizeof(int), 1, file );
	BaselFace_lmInd = new int[BaselFace_lmInd_h*BaselFace_lmInd_w];
	fread ( BaselFace_lmInd, sizeof(int), BaselFace_lmInd_h * BaselFace_lmInd_w, file );
	fread ( &BaselFace_lmInd2_h, sizeof(int), 1, file );
	fread ( &BaselFace_lmInd2_w, sizeof(int), 1, file );
	BaselFace_lmInd2 = new int[BaselFace_lmInd2_h*BaselFace_lmInd2_w];
	fread ( BaselFace_lmInd2, sizeof(int), BaselFace_lmInd2_h * BaselFace_lmInd2_w, file );
	fread ( &BaselFace_keepV_h, sizeof(int), 1, file );
	fread ( &BaselFace_keepV_w, sizeof(int), 1, file );
	BaselFace_keepV = new char[BaselFace_keepV_h*BaselFace_keepV_w];
	fread ( BaselFace_keepV, sizeof(char), BaselFace_keepV_h * BaselFace_keepV_w, file );
	fread ( &BaselFace_faces_extra_h, sizeof(int), 1, file );
	fread ( &BaselFace_faces_extra_w, sizeof(int), 1, file );
	BaselFace_faces_extra = new int[BaselFace_faces_extra_h*BaselFace_faces_extra_w];
	fread ( BaselFace_faces_extra, sizeof(int), BaselFace_faces_extra_h * BaselFace_faces_extra_w, file );
	fread ( &BaselFace_mid_h, sizeof(int), 1, file );
	fread ( &BaselFace_mid_w, sizeof(int), 1, file );
	BaselFace_mid = new char[BaselFace_mid_h*BaselFace_mid_w];
	fread ( BaselFace_mid, sizeof(char), BaselFace_mid_h * BaselFace_mid_w, file );
	fread ( &BaselFace_texEdges_h, sizeof(int), 1, file );
	fread ( &BaselFace_texEdges_w, sizeof(int), 1, file );
	BaselFace_texEdges = new int[BaselFace_texEdges_h*BaselFace_texEdges_w];
	fread ( BaselFace_texEdges, sizeof(int), BaselFace_texEdges_h * BaselFace_texEdges_w, file );
	fread ( &BaselFace_canContour_h, sizeof(int), 1, file );
	fread ( &BaselFace_canContour_w, sizeof(int), 1, file );
	BaselFace_canContour = new char[BaselFace_canContour_h*BaselFace_canContour_w];
	fread ( BaselFace_canContour, sizeof(char), BaselFace_canContour_h * BaselFace_canContour_w, file );
	fread ( &BaselFace_keepVT_h, sizeof(int), 1, file );
	fread ( &BaselFace_keepVT_w, sizeof(int), 1, file );
	BaselFace_keepVT = new int[BaselFace_keepVT_h*BaselFace_keepVT_w];
	fread ( BaselFace_keepVT, sizeof(int), BaselFace_keepVT_h * BaselFace_keepVT_w, file );
	fread ( &BaselFace_pair_h, sizeof(int), 1, file );
	fread ( &BaselFace_pair_w, sizeof(int), 1, file );
	BaselFace_pair = new int[BaselFace_pair_h*BaselFace_pair_w];
	fread ( BaselFace_pair, sizeof(int), BaselFace_pair_h * BaselFace_pair_w, file );
	fread ( &BaselFace_pairKeepVT_h, sizeof(int), 1, file );
	fread ( &BaselFace_pairKeepVT_w, sizeof(int), 1, file );
	BaselFace_pairKeepVT = new int[BaselFace_pairKeepVT_h*BaselFace_pairKeepVT_w];
	fread ( BaselFace_pairKeepVT, sizeof(int), BaselFace_pairKeepVT_h * BaselFace_pairKeepVT_w, file );
	fread ( &BaselFace_vseg_bin_h, sizeof(int), 1, file );
	fread ( &BaselFace_vseg_bin_w, sizeof(int), 1, file );
	BaselFace_vseg_bin = new char[BaselFace_vseg_bin_h*BaselFace_vseg_bin_w];
	fread ( BaselFace_vseg_bin, sizeof(char), BaselFace_vseg_bin_h * BaselFace_vseg_bin_w, file );
	fread ( &BaselFace_indPX_h, sizeof(int), 1, file );
	fread ( &BaselFace_indPX_w, sizeof(int), 1, file );
	BaselFace_indPX = new int[BaselFace_indPX_h*BaselFace_indPX_w];
	fread ( BaselFace_indPX, sizeof(int), BaselFace_indPX_h * BaselFace_indPX_w, file );
	fread ( &BaselFace_indNX_h, sizeof(int), 1, file );
	fread ( &BaselFace_indNX_w, sizeof(int), 1, file );
	BaselFace_indNX = new int[BaselFace_indNX_h*BaselFace_indNX_w];
	fread ( BaselFace_indNX, sizeof(int), BaselFace_indNX_h * BaselFace_indNX_w, file );
	fread ( &BaselFace_symSPC_h, sizeof(int), 1, file );
	fread ( &BaselFace_symSPC_w, sizeof(int), 1, file );
	BaselFace_symSPC = new float[BaselFace_symSPC_h*BaselFace_symSPC_w];
	fread ( BaselFace_symSPC, sizeof(float), BaselFace_symSPC_h * BaselFace_symSPC_w, file );
	fread ( &BaselFace_symTPC_h, sizeof(int), 1, file );
	fread ( &BaselFace_symTPC_w, sizeof(int), 1, file );
	BaselFace_symTPC = new float[BaselFace_symTPC_h*BaselFace_symTPC_w];
	fread ( BaselFace_symTPC, sizeof(float), BaselFace_symTPC_h * BaselFace_symTPC_w, file );
	fread ( &BaselFace_expMU_h, sizeof(int), 1, file );
	fread ( &BaselFace_expMU_w, sizeof(int), 1, file );
	BaselFace_expMU = new float[BaselFace_expMU_h*BaselFace_expMU_w];
	fread ( BaselFace_expMU, sizeof(float), BaselFace_expMU_h * BaselFace_expMU_w, file );
	fread ( &BaselFace_expEV_h, sizeof(int), 1, file );
	fread ( &BaselFace_expEV_w, sizeof(int), 1, file );
	BaselFace_expEV = new float[BaselFace_expEV_h*BaselFace_expEV_w];
	fread ( BaselFace_expEV, sizeof(float), BaselFace_expEV_h * BaselFace_expEV_w, file );
	fread ( &BaselFace_expPC_h, sizeof(int), 1, file );
	fread ( &BaselFace_expPC_w, sizeof(int), 1, file );
	BaselFace_expPC = new float[BaselFace_expPC_h*BaselFace_expPC_w];
	fread ( BaselFace_expPC, sizeof(float), BaselFace_expPC_h * BaselFace_expPC_w, file );
	fread ( &BaselFace_expPCFlip_h, sizeof(int), 1, file );
	fread ( &BaselFace_expPCFlip_w, sizeof(int), 1, file );
	BaselFace_expPCFlip = new float[BaselFace_expPCFlip_h*BaselFace_expPCFlip_w];
	fread ( BaselFace_expPCFlip, sizeof(float), BaselFace_expPCFlip_h * BaselFace_expPCFlip_w, file );
	fclose(file);
	return true;
}
