

struct snew_Skin {
  int XSuits = 403003;
  int XSuits1 = 40604002;
  int Balo1 = 501001;
  int Balo2 = 501002;
  int Balo3 = 501003;
  int Balo4 = 501004;
  int Balo5 = 501005;
  int Balo6 = 501006;
  int Helmet1 = 502001;
  int Helmet2 = 502002;
  int Helmet3 = 502003;
  int Helmet4 = 502004;
  int Helmet5 = 502005;

  int Helmet6 = 502114;
  int Helmet7 = 502115;
  int Helmet8 = 502116;
  int Parachute = 703001;

  int AKM = 101001;
  int AKM_Mag = 291001;
  int M16A4 = 101002;
  int M16A4_Stock = 205007;
  int M16A4_Mag = 291002;
  int Scar = 101003;
  int Scar_Mag = 291003;
  int Pan = 108004;

  int M416_1 = 101004;
  int M416_2 = 291004;
  int M416_3 = 203008;
  int M416_4 = 205005;
  int M416_flash = 201010;
  int M416_compe = 201009;
  int M416_silent = 201011;
  int M416_reddot = 203001;
  int M416_holo = 203001;
  int M416_x2 = 203003;
  int M416_x3 = 203014;
  int M416_x4 = 203004;
  int M416_x6 = 203015;
  int M416_quickMag = 204012;
  int M416_extendedMag = 204011;
  int M416_quickNextended = 204013;
  int M416_stock = 205002;
  int M416_verical = 203015;
  int M416_angle = 202001;
  int M416_lightgrip = 202004;
  int M416_pink = 202005;
  int M416_lazer = 202007;
  int M416_thumb = 202006;

  int Groza = 101005;
  int QBZ = 101007;
  int AUG = 101006;
  int M762 = 101008;
  int M762_Mag = 291008;
  int ACE32 = 101102;
  int P90;
  int FAMAS;
  int Honey = 101012;
  int UZI = 102001;
  int UMP = 102002;
  int Vector = 102003;
  int Thompson = 102004;
  int Bizon = 102005;
  int K98 = 103001;
  int M24 = 103002;
  int AWM = 103003;
  int AMR = 103012;
  int VSS = 103005;
  int SKS = 103004;
  int Mini14 = 103006;
  int MK14 = 103007;
  int SLR = 103009;
  int S1897 = 104002;
  int DP28 = 105002;
  int M249 = 105001;
  int MG3 = 105010;
  int Skorpion = 106008;
  int Moto = 1901001;
  int CoupeRP = 1961001;
  int Dacia = 1903001;
  int UAZ = 1908001;
  int Bigfoot = 1953001;
  int Mirado = 1914004;
  int OMirado = 1915001;
  int Buggy = 1907001;
  int MiniBus = 1904001;
  int Boat = 1911001;
  int M249s = 205009;
  
  int baglv1 = 501001;
    int baglv2 = 501002;
    int baglv3 = 501003;
    int baglv4 = 501004;
  int baglv5 = 501005;
  int baglv6 = 501006;
    
    
    int helmetlv1 = 502001;
    int helmetlv2 = 502002;
    int helmetlv3 = 502003;
    int helmetlv4 = 502004;
  int helmetlv5 = 502005;

  int helmetlv6 = 502114;
  int helmetlv7 = 502115;
  int helmetlv8 = 502116;
};

inline snew_Skin new_Skin;



  void updateSkin() {
  if (akmSkinHackHudSdk == 0) {
    new_Skin.AKM = 101001;//AKM
    new_Skin.AKM_Mag = 205005;
  }
  if (akmSkinHackHudSdk == 1) {
    new_Skin.AKM = 1101001089;// Glacier - AKM (Lv. 7)
    new_Skin.AKM_Mag = 1010010891;
  }
  if (akmSkinHackHudSdk == 2) {
    new_Skin.AKM = 1101001103;//Desert Fossil - AKM (Lv. 7)
    new_Skin.AKM_Mag = 1010011031;
  }
  if (akmSkinHackHudSdk == 3) {
    new_Skin.AKM = 1101001116;//Jack-o'-lantern - AKM (Lv. 7)
    new_Skin.AKM_Mag = 1010011161;
  }
  if (akmSkinHackHudSdk == 4) {
    new_Skin.AKM = 1101001128;//Ghillie Dragon - AKM (Lv. 7)
    new_Skin.AKM_Mag = 1010011281;
  }
  if (akmSkinHackHudSdk == 5) {
    new_Skin.AKM = 1101001143;//Gold Pirate - AKM (Lv. 7)
    new_Skin.AKM_Mag = 1010011431;
  }
  if (akmSkinHackHudSdk == 6) {
    new_Skin.AKM = 1101001154;//Codebreaker - AKM (Lv. 7)
    new_Skin.AKM_Mag = 1010011541;
  }
  if (akmSkinHackHudSdk == 7) {
    new_Skin.AKM = 1101001174;//Wandering Tyrant - AKM (Lv. 8)
    new_Skin.AKM_Mag = 1010011741;
  }
  if (akmSkinHackHudSdk == 8) {
    new_Skin.AKM = 1101001213;//Starsea Admiral - AKM (Lv. 8)
    new_Skin.AKM_Mag = 1010012131;
  }
  if (akmSkinHackHudSdk == 9) {
    new_Skin.AKM = 1101001231;//Bunny Munchkin - AKM (Lv. 7)
    new_Skin.AKM_Mag = 1010012311;
  }
  if (akmSkinHackHudSdk == 10) {
    new_Skin.AKM = 1101001242;//Decisive Day - AKM (Lv. 8)
    new_Skin.AKM_Mag = 1010012421;
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (kerSkinHackHudSdk == 0)
    new_Skin.K98 = 103001;
  if (kerSkinHackHudSdk == 1)
    new_Skin.K98 = 1103001060;//Terror Fang - Kar98K (Lv. 7)
  if (kerSkinHackHudSdk == 2)
    new_Skin.K98 = 1103001079;//Kukulkan Fury - Kar98K (Lv. 7)
  if (kerSkinHackHudSdk == 3)
    new_Skin.K98 = 1103001101;//Moonlit Grace - Kar98K (Lv. 7)
  if (kerSkinHackHudSdk == 4)
    new_Skin.K98 = 1103001146;//Titanium Shark - Kar98K (Lv. 7)
  if (kerSkinHackHudSdk == 5)
    new_Skin.K98 = 1103001160;//Nebula Hunter - Kar98K (Lv. 5)
  if (kerSkinHackHudSdk == 6)
    new_Skin.K98 = 1103001179;//Violet Volt - Kar98K (Lv. 7)
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (awmSkinHackHudSdk == 0)
    new_Skin.AWM = 103003;
  if (awmSkinHackHudSdk == 1)
    new_Skin.AWM = 1103003022;//Mauve Avenger - AWM (Lv. 7)
  if (awmSkinHackHudSdk == 2)
    new_Skin.AWM = 1103003030;//Field Commander - AWM (Lv. 7)
  if (awmSkinHackHudSdk == 3)
    new_Skin.AWM = 1103003042;//Godzilla - AWM (Lv. 7)
  if (awmSkinHackHudSdk == 4)
    new_Skin.AWM = 1103003051;//Rainbow Drake - AWM (Lv. 7)
  if (awmSkinHackHudSdk == 5)
    new_Skin.AWM = 1103003062;//Flamewave - AWM (Lv. 7)
  if (awmSkinHackHudSdk == 6)
    new_Skin.AWM = 1103003087;//Serpengleam - AWM (Lv. 7)
  if (awmSkinHackHudSdk == 7)
    new_Skin.AWM = 1103003055;//Bramble Overlord - AWM
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (m24SkinHackHudSdk == 0)
    new_Skin.M24 = 103002;
  if (m24SkinHackHudSdk == 1)
    new_Skin.M24 = 1103002018;
  if (m24SkinHackHudSdk == 2)
    new_Skin.M24 = 1103002030;
  if (m24SkinHackHudSdk == 3)
    new_Skin.M24 = 1103002049;
  if (m24SkinHackHudSdk == 4)
    new_Skin.M24 = 1103002059;
  if (m24SkinHackHudSdk == 5)
    new_Skin.M24 = 1103002087;
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  if (mini14SkinHackHudSdk == 0)
    new_Skin.Mini14 = 103006; //Mini Normal
  if (mini14SkinHackHudSdk == 1)
    new_Skin.Mini14 = 1103006030; //Icicle - Mini14 (Lv. 7) 
  if (mini14SkinHackHudSdk == 2)
    new_Skin.Mini14 = 1103006046; // Ethereal Beauty - Mini14 (Lv. 5) 
  if (mini14SkinHackHudSdk == 3)
    new_Skin.Mini14 = 1103006058; //Fortune Cat - Mini14 (Lv. 5) 
  if (mini14SkinHackHudSdk == 4)
    new_Skin.Mini14 = 1103006063; //Gallant Jockey - Mini14 (Lv. 5) 
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (ace32SkinHackHudSdk == 0)
    new_Skin.ACE32 = 101102;
  if (ace32SkinHackHudSdk == 1)
    new_Skin.ACE32 = 1101102007;//ADD
  if (ace32SkinHackHudSdk == 2)
    new_Skin.ACE32 = 1101102017;//ADD
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   if (vectorSkinHackHudSdk == 0)
    new_Skin.Vector = 102003;
  if (vectorSkinHackHudSdk == 1)
    new_Skin.Vector = 1102003020;//ADD
  if (vectorSkinHackHudSdk == 2)
    new_Skin.Vector = 1102003031;//ADD
  if (vectorSkinHackHudSdk == 3)
    new_Skin.Vector = 1102003065;//ADD
  if (vectorSkinHackHudSdk == 4)
    new_Skin.Vector = 1102003080;//ADD
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   if (ump45SkinHackHudSdk == 0)
    new_Skin.UMP = 102002;
  if (ump45SkinHackHudSdk == 1)
    new_Skin.UMP = 1102002043;//ADD
  if (ump45SkinHackHudSdk == 2)
    new_Skin.UMP = 1102002061;//ADD
  if (ump45SkinHackHudSdk == 3)
    new_Skin.UMP = 1102002090;//ADD
  if (ump45SkinHackHudSdk == 4)
    new_Skin.UMP = 1102002117;//ADD
  if (ump45SkinHackHudSdk == 5)
    new_Skin.UMP = 1102002124;//ADD
  if (ump45SkinHackHudSdk == 6)
    new_Skin.UMP = 1102002129;//ADD
  if (ump45SkinHackHudSdk == 7)
    new_Skin.UMP = 1102002136;//ADD
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (uziSkinHackHudSdk == 0)
    new_Skin.UZI = 102001;
  if (uziSkinHackHudSdk == 1)
    new_Skin.UZI = 1102001024;//ADD
  if (uziSkinHackHudSdk == 2)
    new_Skin.UZI = 1102001036;//ADD
  if (uziSkinHackHudSdk == 3)
    new_Skin.UZI = 1102001058;//ADD
  if (uziSkinHackHudSdk == 4)
    new_Skin.UZI = 1102001069;//ADD
  if (uziSkinHackHudSdk == 5)
    new_Skin.UZI = 1102001089;//ADD
  if (uziSkinHackHudSdk == 6)
    new_Skin.UZI = 1102001102;//ADD
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (thompsonSkinHackHudSdk == 0)
    new_Skin.Thompson = 102004;
  if (thompsonSkinHackHudSdk == 1)
    new_Skin.Thompson = 1102004018;//Candy Cane - Thompson SMG (Lv. 5)
  if (thompsonSkinHackHudSdk == 2)
    new_Skin.Thompson = 1102004034;//Steampunk - Thompson SMG (Lv. 5)
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (m16a4SkinHackHudSdk == 0) {
    new_Skin.M16A4 = 101002;
    new_Skin.M16A4_Stock = 205007;
    new_Skin.M16A4_Mag = 291002;
  }
  if (m16a4SkinHackHudSdk == 1) {
    new_Skin.M16A4 = 1101002029;//ADD
    new_Skin.M16A4_Stock = 1010020292;
    new_Skin.M16A4_Mag = 1010020291;
  }
  if (m16a4SkinHackHudSdk == 2) {
    new_Skin.M16A4 = 1101002056;//ADD
    new_Skin.M16A4_Stock = 1010020562;
    new_Skin.M16A4_Mag = 1010020561;
  }
  if (m16a4SkinHackHudSdk == 3) {
    new_Skin.M16A4 = 1101002068;//ADD
    new_Skin.M16A4_Stock = 1010020682;
    new_Skin.M16A4_Mag = 1010020681;
  }
  if (m16a4SkinHackHudSdk == 4) {
    new_Skin.M16A4 = 1101002081;//ADD
    new_Skin.M16A4_Stock = 1010020812;
    new_Skin.M16A4_Mag = 1010020811;
  }
  if (m16a4SkinHackHudSdk == 5) {
    new_Skin.M16A4 = 1101002103;//ADD
    new_Skin.M16A4_Stock = 1010021032;
    new_Skin.M16A4_Mag = 1010021031;
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (augSkinHackHudSdk == 0)
    new_Skin.AUG = 101006;
  if (augSkinHackHudSdk == 1)
    new_Skin.AUG = 1101006033;//ADD
  if (augSkinHackHudSdk == 2)
    new_Skin.AUG = 1101006044;//ADD
  if (augSkinHackHudSdk == 3)
    new_Skin.AUG = 1101006062;//ADD
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (grozaSkinHackHudSdk == 0) 
    new_Skin.Groza = 101005;
  if (grozaSkinHackHudSdk == 1) 
    new_Skin.Groza = 1101005019;
  if (grozaSkinHackHudSdk == 2) 
    new_Skin.Groza = 1101005025;
  if (grozaSkinHackHudSdk == 3) 
    new_Skin.Groza = 1101005038;
  if (grozaSkinHackHudSdk == 4) 
    new_Skin.Groza = 1101005043;
  if (grozaSkinHackHudSdk == 5) 
    new_Skin.Groza = 1101005052;
  if (grozaSkinHackHudSdk == 6) 
    new_Skin.Groza = 1101005082;
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (dp28SkinHackHudSdk == 0)
    new_Skin.DP28 = 105002;
  if (dp28SkinHackHudSdk == 1)
    new_Skin.DP28 = 1105002018;
  if (dp28SkinHackHudSdk == 2)
    new_Skin.DP28 = 1105002035;
  if (dp28SkinHackHudSdk == 3)
    new_Skin.DP28 = 1105002058;
  if (dp28SkinHackHudSdk == 4)
    new_Skin.DP28 = 1105002063;
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (m249SkinHackHudSdk == 0){
    new_Skin.M249 = 105001;
    new_Skin.M249s = 205009;
    }
  if (m249SkinHackHudSdk == 1){
    new_Skin.M249 = 1105001020;
    new_Skin.M249s = 1050010351;
    }
  if (m249SkinHackHudSdk == 2){
    new_Skin.M249 = 1105001034;
    new_Skin.M249s = 1050010412;
    }
  if (m249SkinHackHudSdk == 3){
    new_Skin.M249 = 1105001048;
    new_Skin.M249s = 1050010482;
    }
  if (m249SkinHackHudSdk == 4){
    new_Skin.M249 = 1105001054;
    new_Skin.M249s = 1050010542;
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (scarSkinHackHudSdk == 0) {
    new_Skin.Scar = 101003;
    new_Skin.Scar_Mag = 291003;
  }
  if (scarSkinHackHudSdk == 1) {
    new_Skin.Scar = 1101003057;
    new_Skin.Scar_Mag = 1010030571;
  }
  if (scarSkinHackHudSdk == 2) {
    new_Skin.Scar = 1101003070;
    new_Skin.Scar_Mag = 1010030701;
  }
  if (scarSkinHackHudSdk == 3) {
    new_Skin.Scar = 1101003080;
    new_Skin.Scar_Mag = 1010030801;
  }
  if (scarSkinHackHudSdk == 4) {
    new_Skin.Scar = 1101003119;
    new_Skin.Scar_Mag = 1010031191;
  }
  if (scarSkinHackHudSdk == 5) {
    new_Skin.Scar = 1101003146;
    new_Skin.Scar_Mag = 1010031461;
  }
  if (scarSkinHackHudSdk == 6) {
    new_Skin.Scar = 1101003167;
    new_Skin.Scar_Mag = 1010031671;
  }
  if (scarSkinHackHudSdk == 7) {
    new_Skin.Scar = 1101003181;
    new_Skin.Scar_Mag = 1010031811;
  }
  ///////////////////////////////////
    if (m762SkinHackHudSdk == 0) {
    new_Skin.M762 = 101008;
    new_Skin.M762_Mag = 291008;
  }
  if (m762SkinHackHudSdk == 1) {
    new_Skin.M762 = 1101008026;
    new_Skin.M762_Mag = 1010080261;
  }
  if (m762SkinHackHudSdk == 2) {
    new_Skin.M762 = 1101008051;
    new_Skin.M762_Mag = 1010080511;
  }
  if (m762SkinHackHudSdk == 3) {
    new_Skin.M762 = 1101008061;
    new_Skin.M762_Mag = 1010080611;
  }
  if (m762SkinHackHudSdk == 4) {
    new_Skin.M762 = 1101008081;
    new_Skin.M762_Mag = 1010080811;
  }
  if (m762SkinHackHudSdk == 5) {
    new_Skin.M762 = 1101008104;
    new_Skin.M762_Mag = 1010081041;
  }
  if (m762SkinHackHudSdk == 6) {
    new_Skin.M762 = 1101008116;
    new_Skin.M762_Mag = 1010081161;
  }
  if (m762SkinHackHudSdk == 7) {
    new_Skin.M762 = 1101008126;
    new_Skin.M762_Mag = 1010081261;
  }
 
  if (m762SkinHackHudSdk == 8) {
    new_Skin.M762 = 1101008070;
    new_Skin.M762_Mag = 1010030801;
  }
  
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (m4SkinHackHudSdk == 0) {
    new_Skin.M416_1 = 101004;
    new_Skin.M416_2 = 291004;
    new_Skin.M416_3 = 203008;
    new_Skin.M416_4 = 205005;
    new_Skin.M416_flash = 201010;
    new_Skin.M416_compe = 201009;
    new_Skin.M416_silent = 201011;
    new_Skin.M416_reddot = 203001;
    new_Skin.M416_holo = 203002;
    new_Skin.M416_x2 = 203003;
    new_Skin.M416_x3 = 203014;
    new_Skin.M416_x4 = 203004;
    new_Skin.M416_x6 = 203015;
    new_Skin.M416_quickMag = 204012;
    new_Skin.M416_extendedMag = 204011;
    new_Skin.M416_quickNextended = 204013;
    new_Skin.M416_stock = 205002;
    new_Skin.M416_verical = 203015;
    new_Skin.M416_angle = 202001;
    new_Skin.M416_lightgrip = 202004;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 1) { //glacier
    new_Skin.M416_1 = 1101004046;
    new_Skin.M416_2 = 1010040461;
    new_Skin.M416_3 = 1010040462;
    new_Skin.M416_4 = 1010040463;
    new_Skin.M416_flash = 1010040474;
    new_Skin.M416_compe = 1010040475;
    new_Skin.M416_silent = 1010040476;
    new_Skin.M416_reddot = 1010040470;
    new_Skin.M416_holo = 1010040469;
    new_Skin.M416_x2 = 1010040468;
    new_Skin.M416_x3 = 1010040467;
    new_Skin.M416_x4 = 1010040466;
    new_Skin.M416_x6 = 1010040481;
    new_Skin.M416_quickMag = 1010040472;
    new_Skin.M416_extendedMag = 1010040473;
    new_Skin.M416_quickNextended = 1010040473;
    new_Skin.M416_stock = 1010040480;
    new_Skin.M416_verical = 1010040479;
    new_Skin.M416_thumb = 1010040478;
    new_Skin.M416_angle = 1010040477;
    new_Skin.M416_lightgrip = 1010040482;
    new_Skin.M416_pink = 1010040483;
    new_Skin.M416_lazer = 1010040484;
  }
  if (m4SkinHackHudSdk == 2) { //thefool
    new_Skin.M416_1 = 1101004062;
    new_Skin.M416_2 = 1010040611;
    new_Skin.M416_3 = 1010040612;
    new_Skin.M416_4 = 1010040613;
    new_Skin.M416_flash = 201010;
    new_Skin.M416_compe = 201009;
    new_Skin.M416_silent = 201011;
    new_Skin.M416_reddot = 203001;
    new_Skin.M416_holo = 203002;
    new_Skin.M416_x2 = 203003;
    new_Skin.M416_x3 = 203014;
    new_Skin.M416_x4 = 203004;
    new_Skin.M416_x6 = 203015;
    new_Skin.M416_quickMag = 204012;
    new_Skin.M416_extendedMag = 204011;
    new_Skin.M416_quickNextended = 204013;
    new_Skin.M416_stock = 205002;
    new_Skin.M416_verical = 203015;
    new_Skin.M416_angle = 202001;
    new_Skin.M416_lightgrip = 202004;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 3) { //Wanderer
    new_Skin.M416_1 = 1101004078;
    new_Skin.M416_2 = 1010040781;
    new_Skin.M416_3 = 1010040782;
    new_Skin.M416_4 = 1010040783;
    new_Skin.M416_flash = 201010;
    new_Skin.M416_compe = 201009;
    new_Skin.M416_silent = 201011;
    new_Skin.M416_reddot = 203001;
    new_Skin.M416_holo = 203002;
    new_Skin.M416_x2 = 203003;
    new_Skin.M416_x3 = 203014;
    new_Skin.M416_x4 = 203004;
    new_Skin.M416_x6 = 203015;
    new_Skin.M416_quickMag = 204012;
    new_Skin.M416_extendedMag = 204011;
    new_Skin.M416_quickNextended = 204013;
    new_Skin.M416_stock = 205002;
    new_Skin.M416_verical = 203015;
    new_Skin.M416_angle = 202001;
    new_Skin.M416_lightgrip = 202004;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 4) { //Lz
    new_Skin.M416_1 = 1101004086;
    new_Skin.M416_2 = 1010040861;
    new_Skin.M416_3 = 1010040862;
    new_Skin.M416_4 = 1010040863;
    new_Skin.M416_flash = 201010;
    new_Skin.M416_compe = 201009;
    new_Skin.M416_silent = 201011;
    new_Skin.M416_reddot = 203001;
    new_Skin.M416_holo = 203002;
    new_Skin.M416_x2 = 203003;
    new_Skin.M416_x3 = 203014;
    new_Skin.M416_x4 = 203004;
    new_Skin.M416_x6 = 203015;
    new_Skin.M416_quickMag = 204012;
    new_Skin.M416_extendedMag = 204011;
    new_Skin.M416_quickNextended = 204013;
    new_Skin.M416_stock = 205002;
    new_Skin.M416_verical = 203015;
    new_Skin.M416_angle = 202001;
    new_Skin.M416_lightgrip = 202004;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 5) { //Call of the Wild
    new_Skin.M416_1 = 1101004098;
    new_Skin.M416_2 = 1010040981;
    new_Skin.M416_3 = 1010040982;
    new_Skin.M416_4 = 1010040983;
    new_Skin.M416_flash = 1010041136;
    new_Skin.M416_compe = 1010041137;
    new_Skin.M416_silent = 1010041138;
    new_Skin.M416_reddot = 1010041128;
    new_Skin.M416_holo = 1010041127;
    new_Skin.M416_x2 = 1010041126;
    new_Skin.M416_x3 = 1010041125;
    new_Skin.M416_x4 = 1010041124;
    new_Skin.M416_x6 = 203015;
    new_Skin.M416_quickMag = 1010041134;
    new_Skin.M416_extendedMag = 1010041129;
    new_Skin.M416_quickNextended = 1010041135;
    new_Skin.M416_stock = 1010041146;
    new_Skin.M416_verical = 1010041145;
    new_Skin.M416_angle = 1010041139;
    new_Skin.M416_lightgrip = 1010041144;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 6) { //TechnoCore
    new_Skin.M416_1 = 1101004138;
    new_Skin.M416_2 = 1010041381;
    new_Skin.M416_3 = 1010041382;
    new_Skin.M416_4 = 1010041383;
    new_Skin.M416_flash = 1010041136;
    new_Skin.M416_compe = 1010041137;
    new_Skin.M416_silent = 1010041138;
    new_Skin.M416_reddot = 1010041128;
    new_Skin.M416_holo = 1010041127;
    new_Skin.M416_x2 = 1010041126;
    new_Skin.M416_x3 = 1010041125;
    new_Skin.M416_x4 = 203004;
    new_Skin.M416_x6 = 203015;
    new_Skin.M416_quickMag = 1010041134;
    new_Skin.M416_extendedMag = 1010041129;
    new_Skin.M416_quickNextended = 1010041135;
    new_Skin.M416_stock = 1010041146;
    new_Skin.M416_verical = 1010041145;
    new_Skin.M416_angle = 1010041139;
    new_Skin.M416_lightgrip = 202004;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 7) { //Imperial Splendor
    new_Skin.M416_1 = 1101004163;
    new_Skin.M416_2 = 1010041631;
    new_Skin.M416_3 = 1010041632;
    new_Skin.M416_4 = 1010041633;
    new_Skin.M416_flash = 201010;
    new_Skin.M416_compe = 1010041574;
    new_Skin.M416_silent = 1010041575;
    new_Skin.M416_reddot = 1010041566;
    new_Skin.M416_holo = 1010041565;
    new_Skin.M416_x2 = 1010041564;
    new_Skin.M416_x3 = 1010041560;
    new_Skin.M416_x4 = 1010041554;
    new_Skin.M416_x6 = 203015;
    new_Skin.M416_quickMag = 1010041568;
    new_Skin.M416_extendedMag = 1010041569;
    new_Skin.M416_quickNextended = 1010041567;
    new_Skin.M416_stock = 1010041579;
    new_Skin.M416_verical = 1010041578;
    new_Skin.M416_angle = 1010041576;
    new_Skin.M416_lightgrip = 20200400;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 1010041577;
  }
  if (m4SkinHackHudSdk == 8) { //Silver Guru 
    new_Skin.M416_1 = 1101004201;
    new_Skin.M416_2 = 1010042011;
    new_Skin.M416_3 = 1010042012;
    new_Skin.M416_4 = 1010042013;
    new_Skin.M416_flash = 1010041956;
    new_Skin.M416_compe = 1010041957;
    new_Skin.M416_silent = 1010041958;
    new_Skin.M416_reddot = 1010041948;
    new_Skin.M416_holo = 1010041947;
    new_Skin.M416_x2 = 1010041946;
    new_Skin.M416_x3 = 1010041945;
    new_Skin.M416_x4 = 1010041944;
    new_Skin.M416_x6 = 1010041967;
    new_Skin.M416_quickMag = 1010041949;
    new_Skin.M416_extendedMag = 1010041950;
    new_Skin.M416_quickNextended = 1010041955;
    new_Skin.M416_stock = 1010041966;
    new_Skin.M416_verical = 1010041965;
    new_Skin.M416_angle = 1010041959;
    new_Skin.M416_lightgrip = 202004;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 9) { //*Tidal Embrace
    new_Skin.M416_1 = 1101004209;
    new_Skin.M416_2 = 1010042073;
    new_Skin.M416_3 = 1010042083;
    new_Skin.M416_4 = 1010042093;
    new_Skin.M416_flash = 20101000;
    new_Skin.M416_compe = 1010042037;
    new_Skin.M416_silent = 1010042039;
    new_Skin.M416_reddot = 1010042029;
    new_Skin.M416_holo = 1010042028;
    new_Skin.M416_x2 = 1010042027;
    new_Skin.M416_x3 = 1010042026;
    new_Skin.M416_x4 = 1010042025;
    new_Skin.M416_x6 = 1010042024;
    new_Skin.M416_quickMag = 1010042034;
    new_Skin.M416_extendedMag = 1010042035;
    new_Skin.M416_quickNextended = 1010042036;
    new_Skin.M416_stock = 1010042047;
    new_Skin.M416_verical = 1010042046;
    new_Skin.M416_angle = 1010042044;
    new_Skin.M416_lightgrip = 202004;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 10) { //Shinobi Kami
    new_Skin.M416_1 = 1101004218;
    new_Skin.M416_2 = 1010042153;
    new_Skin.M416_3 = 1010042163;
    new_Skin.M416_4 = 1010042173;
    new_Skin.M416_flash = 1010042128;
    new_Skin.M416_compe = 1010042127;
    new_Skin.M416_silent = 1010042129;
    new_Skin.M416_reddot = 1010042119;
    new_Skin.M416_holo = 1010042118;
    new_Skin.M416_x2 = 1010042117;
    new_Skin.M416_x3 = 1010042116;
    new_Skin.M416_x4 = 1010042115;
    new_Skin.M416_x6 = 1010042114;
    new_Skin.M416_quickMag = 1010042124;
    new_Skin.M416_extendedMag = 1010042125;
    new_Skin.M416_quickNextended = 1010042126;
    new_Skin.M416_stock = 1010042137;
    new_Skin.M416_verical = 1010042136;
    new_Skin.M416_angle = 1010042134;
    new_Skin.M416_lightgrip = 1010042138;
    new_Skin.M416_pink = 1010042139;
    new_Skin.M416_lazer = 1010042144;
    new_Skin.M416_thumb = 1010042135;
  }
  
  if (m4SkinHackHudSdk == 11) { //Sealed Nether
    new_Skin.M416_1 = 1101004226;
    new_Skin.M416_2 = 1010042206;
    new_Skin.M416_3 = 1010042209;
    new_Skin.M416_4 = 1010042213;
    new_Skin.M416_flash = 1010042238;
    new_Skin.M416_compe = 1010042237;
    new_Skin.M416_silent = 1010042239;
    new_Skin.M416_reddot = 1010042233;
    new_Skin.M416_holo = 1010042232;
    new_Skin.M416_x2 = 1010042231;
    new_Skin.M416_x3 = 1010042219;
    new_Skin.M416_x4 = 1010042218;
    new_Skin.M416_x6 = 1010042217;
    new_Skin.M416_quickMag = 1010042235;
    new_Skin.M416_extendedMag = 1010042234;
    new_Skin.M416_quickNextended = 1010042236;
    new_Skin.M416_stock = 1010042244;
    new_Skin.M416_verical = 1010042243;
    new_Skin.M416_angle = 1010042241;
    new_Skin.M416_lightgrip = 1010042245;
    new_Skin.M416_pink = 1010042246;
    new_Skin.M416_lazer = 1010042247;
    new_Skin.M416_thumb = 1010042242;
  }
  
   if (amrSkinHackHudSdk == 0)
    new_Skin.AMR = 103012;
  if (amrSkinHackHudSdk == 1)
    new_Skin.AMR = 1103012010;//Crimson Ephialtes - AMR (Lv. 8) 
  if (amrSkinHackHudSdk == 2)
    new_Skin.AMR = 1103012019;//Scorching Blessing - AMR (Lv. 7) 
    
   if (mk14SkinHackHudSdk == 0)
    new_Skin.MK14 = 103007;
  if (mk14SkinHackHudSdk == 1)
    new_Skin.MK14 = 1103007020;//Gilded Galaxy - Mk14 (Lv. 5) 
    if (mk14SkinHackHudSdk == 2)
    new_Skin.MK14 = 1103007028;//Drakreign - Mk14 (Lv. 8) 
    

  if (MG3SkinHackHudSdk == 0)
    new_Skin.MG3 = 105010;
  if (MG3SkinHackHudSdk == 1)
    new_Skin.MG3 = 1105010008;//Soaring Dragon - MG3 (Lv. 5) 

    
//lv 1
if (bagSkinHackHudSdk == 0)
new_Skin.baglv1 = 501001; //LV 2
if (bagSkinHackHudSdk == 1)
new_Skin.baglv1 = 1501001220; //Blood Raven Backpack (Lv. 1)
if (bagSkinHackHudSdk == 2)
new_Skin.baglv1 = 1501001174; //Pharaoh's Regalia Backpack (Lv. 1)
if (bagSkinHackHudSdk == 3)
new_Skin.baglv1 = 1501001051; //The Fool Backpack (Lv. 1)
if (bagSkinHackHudSdk == 4)
new_Skin.baglv1 = 1501001443; //Luminous Galaxy Backpack (Lv. 1)
if (bagSkinHackHudSdk == 5)
new_Skin.baglv1 = 1501001265; //Poseidon Backpack (Lv. 1)
if (bagSkinHackHudSdk == 6)
new_Skin.baglv1 = 1501001321; //Gackt Moonsaga Backpack(Lv. 1)
if (bagSkinHackHudSdk == 7)
new_Skin.baglv1 = 1501001277; //Godzilla Backpack (Lv. 1)
if (bagSkinHackHudSdk == 8)
new_Skin.baglv1 = 1501001550; //Frosty Snowglobe Backpack (Lv. 1)
if (bagSkinHackHudSdk == 9)
new_Skin.baglv1 = 1501001552; //Ebil Bunny Backpack (Lv. 1)
 if (bagSkinHackHudSdk == 10)
new_Skin.baglv1 = 1501001061; //Godzilla Backpack (Lv. 1)
if (bagSkinHackHudSdk == 11)
new_Skin.baglv1 = 1501001058; //BAPE X PUBGM CAMO Backpack 
if (bagSkinHackHudSdk == 12)
new_Skin.baglv1 = 1501001062; //King Ghidorah Backpack (Lv. 1)
if (bagSkinHackHudSdk == 13)
new_Skin.baglv1 = 1501001422; // Bramble Overlord Backpack (Lv. 1)
if (bagSkinHackHudSdk == 14)
new_Skin.baglv1 = 1501001503; // Bramble Overlord Backpack (Lv. 1)
if (bagSkinHackHudSdk == 15)
new_Skin.baglv1 = 1501001546; // Bramble Overlord Backpack (Lv. 1)



    
//LV-2

if (bagSkinHackHudSdk == 0)
new_Skin.baglv2 = 501002; //LV 2
if (bagSkinHackHudSdk == 1)
new_Skin.baglv2 = 1501002220; //Blood Raven Backpack (Lv. 2)
if (bagSkinHackHudSdk == 2)
new_Skin.baglv2 = 1501002174; //Pharaoh's Regalia Backpack (Lv. 2)
if (bagSkinHackHudSdk == 3)
new_Skin.baglv2 = 1501002051; //The Fool Backpack (Lv. 2)
if (bagSkinHackHudSdk == 4)
new_Skin.baglv2 = 1501002443; //Luminous Galaxy Backpack (Lv. 2)
if (bagSkinHackHudSdk == 5)
new_Skin.baglv2 = 1501002265; //Poseidon Backpack (Lv. 2)
if (bagSkinHackHudSdk == 6)
new_Skin.baglv2 = 1501002321; //Gackt Moonsaga Backpack(Lv. 2)
if (bagSkinHackHudSdk == 7)
new_Skin.baglv2 = 1501002277; //Godzilla Backpack (Lv. 2)
if (bagSkinHackHudSdk == 8)
new_Skin.baglv2 = 1501002550; //Frosty Snowglobe Backpack (Lv. 2)
if (bagSkinHackHudSdk == 9)
new_Skin.baglv2 = 1501002552; //Ebil Bunny Backpack (Lv. 2)
 if (bagSkinHackHudSdk == 10)
new_Skin.baglv2 = 1501002061; //Godzilla Backpack (Lv. 2)
if (bagSkinHackHudSdk == 11)
new_Skin.baglv2 = 1501002058; //BAPE X PUBGM CAMO Backpack 
if (bagSkinHackHudSdk == 12)
new_Skin.baglv2 = 1501002062; //King Ghidorah Backpack (Lv. 2)
if (bagSkinHackHudSdk == 13)
new_Skin.baglv2 = 1501002422; // Bramble Overlord Backpack (Lv. 2)
if (bagSkinHackHudSdk == 14)
new_Skin.baglv2 = 1501002503; // Bramble Overlord Backpack (Lv. 2)
if (bagSkinHackHudSdk == 15)
new_Skin.baglv2 = 1501002546; // Bramble Overlord Backpack (Lv. 2)





//LV-3
if (bagSkinHackHudSdk == 0)
new_Skin.baglv3 = 501003; //LV 3
if (bagSkinHackHudSdk == 1)
new_Skin.baglv3 = 1501003220; //Blood Raven Backpack (Lv. 3)
if (bagSkinHackHudSdk == 2)
new_Skin.baglv3 = 1501003174; //Pharaoh's Regalia Backpack (Lv. 3)
if (bagSkinHackHudSdk == 3)
new_Skin.baglv3 = 1501003051; //The Fool Backpack (Lv. 3)
if (bagSkinHackHudSdk == 4)
new_Skin.baglv3 = 1501003443; //Luminous Galaxy Backpack (Lv. 3)
if (bagSkinHackHudSdk == 5)
new_Skin.baglv3 = 1501003265; //Poseidon Backpack (Lv. 3)
if (bagSkinHackHudSdk == 6)
new_Skin.baglv3 = 1501003321; //Gackt Moonsaga Backpack(Lv. 3)
if (bagSkinHackHudSdk == 7)
new_Skin.baglv3 = 1501003277; //Godzilla Backpack (Lv. 3)
if (bagSkinHackHudSdk == 8)
new_Skin.baglv3 = 1501003550; //Frosty Snowglobe Backpack (Lv. 3)
if (bagSkinHackHudSdk == 9)
new_Skin.baglv3 = 1501003552; //Ebil Bunny Backpack (Lv. 3)
 if (bagSkinHackHudSdk == 10)
new_Skin.baglv3 = 1501003061; //Godzilla Backpack (Lv. 3)
if (bagSkinHackHudSdk == 11)
new_Skin.baglv3 = 1501003058; //BAPE X PUBGM CAMO Backpack 
if (bagSkinHackHudSdk == 12)
new_Skin.baglv3 = 1501003062; //King Ghidorah Backpack (Lv. 3)
if (bagSkinHackHudSdk == 13)
new_Skin.baglv3 = 1501003422; // Bramble Overlord Backpack (Lv. 3)
if (bagSkinHackHudSdk == 14)
new_Skin.baglv3 = 1501003503; // Bramble Overlord Backpack (Lv. 3)
if (bagSkinHackHudSdk == 15)
new_Skin.baglv3 = 1501003546; // Bramble Overlord Backpack (Lv. 3)




//lv-1
if (helmetSkinHackHudSdk == 0)
new_Skin.helmetlv1 = 502001; //lv 1
if (helmetSkinHackHudSdk == 1)
new_Skin.helmetlv1 = 1502001028; //Scarlet Beast Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 2)
new_Skin.helmetlv1 = 1502001014; //Inferno Rider Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 3)
new_Skin.helmetlv1 = 1502001023; //Glacier Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 4)
new_Skin.helmetlv1 = 1502001065; //Moon Bunny Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 5)
new_Skin.helmetlv1 = 1502001031; //Mutated Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 6)
new_Skin.helmetlv1 = 1502001033; //Intergalactic Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 7)
new_Skin.helmetlv1 = 1502001069; //Masked Psychic Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 8)
new_Skin.helmetlv1 = 1502001261; //Atlantic Tech Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 9)
new_Skin.helmetlv1 = 1502001272; //Mystic Battle Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 10)
new_Skin.helmetlv1 = 1502001183; //Godzilla Helmet (Lv. 1)


//lv-2
if (helmetSkinHackHudSdk == 0)
new_Skin.helmetlv2 = 502002; //lv 2
if (helmetSkinHackHudSdk == 1)
new_Skin.helmetlv2 = 1502002028; //Scarlet Beast Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 2)
new_Skin.helmetlv2 = 1502002014; //Inferno Rider Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 3)
new_Skin.helmetlv2 = 1502002023; //Glacier Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 4)
new_Skin.helmetlv2 = 1502002065; //Moon Bunny Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 5)
new_Skin.helmetlv2 = 1502002031; //Mutated Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 6)
new_Skin.helmetlv2 = 1502002033; //Intergalactic Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 7)
new_Skin.helmetlv2 = 1502002069; //Masked Psychic Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 8)
new_Skin.helmetlv2 = 1502002261; //Atlantic Tech Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 9)
new_Skin.helmetlv2 = 1502002272; //Mystic Battle Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 10)
new_Skin.helmetlv2 = 1502002183; //Godzilla Helmet (Lv. 2)


//lv-3
if (helmetSkinHackHudSdk == 0)
new_Skin.helmetlv3 = 502003; //lv 3
if (helmetSkinHackHudSdk == 1)
new_Skin.helmetlv3 = 1502003028; //Scarlet Beast Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 2)
new_Skin.helmetlv3 = 1502003014; //Inferno Rider Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 3)
new_Skin.helmetlv3 = 1502003023; //Glacier Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 4)
new_Skin.helmetlv3 = 1502003065; //Moon Bunny Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 5)
new_Skin.helmetlv3 = 1502003031; //Mutated Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 6)
new_Skin.helmetlv3 = 1502003033; //Intergalactic Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 7)
new_Skin.helmetlv3 = 1502003069; //Masked Psychic Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 8)
new_Skin.helmetlv3 = 1502003261; //Atlantic Tech Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 9)
new_Skin.helmetlv3 = 1502003272; //Mystic Battle Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 10)
new_Skin.helmetlv3 = 1502003183; //Godzilla Helmet (Lv. 3)



  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Monster Truck
BigfootSkinHackSdk
*/
   if (BigfootSkinHackSdk == 0)
    new_Skin.Bigfoot = 1953001;
  if (BigfootSkinHackSdk == 1)
    new_Skin.Bigfoot = 1953004;
    
 //   Mirado (Open Top)
 //   MiradoSkinHackSdk
  if (MiradoSkinHackSdk == 0)
    new_Skin.OMirado = 1915001;
  if (MiradoSkinHackSdk == 1)
    new_Skin.OMirado = 1915011;
  if (MiradoSkinHackSdk == 2)
    new_Skin.OMirado = 1915099;
    
   // Mirado (Closed Top)
    //FMiradoSkinHackSdk
  if (MiradoSkinHackSdk == 0)
    new_Skin.Mirado = 1914001;
  if (FMiradoSkinHackSdk == 1)
    new_Skin.Mirado = 1914011;
    
    //Motorcycle
    //MotoSkinHackSdk
  if (MotoSkinHackSdk == 0)
    new_Skin.Moto = 1901001;
  if (MotoSkinHackSdk == 1)
    new_Skin.Moto = 1901073;
  if (MotoSkinHackSdk == 2)
    new_Skin.Moto = 1901074;
  if (MotoSkinHackSdk == 3)
    new_Skin.Moto = 1901075;
  if (MotoSkinHackSdk == 4)
    new_Skin.Moto = 1901076;
  if (MotoSkinHackSdk == 5)
    new_Skin.Moto = 1901047;
  if (MotoSkinHackSdk == 6)
    new_Skin.Moto = 1901085;
  if (MotoSkinHackSdk == 7)
    new_Skin.Moto = 1901027;
  if (MotoSkinHackSdk == 8)
    new_Skin.Moto = 1901018;
    

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //Buggy
  //BuggySkinHackSdk
if (BuggySkinHackSdk == 0)
    new_Skin.Buggy = 1907001;
  if (BuggySkinHackSdk == 1)
    new_Skin.Buggy = 1907047;
  if (BuggySkinHackSdk == 2)
    new_Skin.Buggy = 1907009;
if (BuggySkinHackSdk == 3)
    new_Skin.Buggy = 1907010;
if (BuggySkinHackSdk == 4)
    new_Skin.Buggy = 1907011;
if (BuggySkinHackSdk == 5)
    new_Skin.Buggy = 1907012;
if (BuggySkinHackSdk == 6)
    new_Skin.Buggy = 1907013;
if (BuggySkinHackSdk == 7)
    new_Skin.Buggy = 1907014;
if (BuggySkinHackSdk == 8)
    new_Skin.Buggy = 1907015;
if (BuggySkinHackSdk == 9)
    new_Skin.Buggy = 1907016;
if (BuggySkinHackSdk == 10)
    new_Skin.Buggy = 1907017;
if (BuggySkinHackSdk == 11)
    new_Skin.Buggy = 1907018;
if (BuggySkinHackSdk == 12)
    new_Skin.Buggy = 1907019;
if (BuggySkinHackSdk == 13)
    new_Skin.Buggy = 1907020;
if (BuggySkinHackSdk == 14)
    new_Skin.Buggy = 1907021;
if (BuggySkinHackSdk == 15)
    new_Skin.Buggy = 1907022;
if (BuggySkinHackSdk == 16)
    new_Skin.Buggy = 1907023;
if (BuggySkinHackSdk == 17)
    new_Skin.Buggy = 1907024;
if (BuggySkinHackSdk == 18)
    new_Skin.Buggy = 1907025;
if (BuggySkinHackSdk == 19)
    new_Skin.Buggy = 1907026;
if (BuggySkinHackSdk == 20)
    new_Skin.Buggy = 1907027;
if (BuggySkinHackSdk == 21)
    new_Skin.Buggy = 1907028;
if (BuggySkinHackSdk == 22)
    new_Skin.Buggy = 1907029;
if (BuggySkinHackSdk == 23)
    new_Skin.Buggy = 1907030;
if (BuggySkinHackSdk == 24)
    new_Skin.Buggy = 1907031;
if (BuggySkinHackSdk == 25)
    new_Skin.Buggy = 1907032;
if (BuggySkinHackSdk == 26)
    new_Skin.Buggy = 1907033;
if (BuggySkinHackSdk == 27)
    new_Skin.Buggy = 1907034;
if (BuggySkinHackSdk == 28)
    new_Skin.Buggy = 1907035;
if (BuggySkinHackSdk == 29)
    new_Skin.Buggy = 1907036;
if (BuggySkinHackSdk == 30)
    new_Skin.Buggy = 1907037;
if (BuggySkinHackSdk == 31)
    new_Skin.Buggy = 1907038;
if (BuggySkinHackSdk == 32)
    new_Skin.Buggy = 1907039;
if (BuggySkinHackSdk == 33)
    new_Skin.Buggy = 1907040;
    
    //Dacia
    //DaciaSkinHackSdk
    
                    if (DaciaSkinHackSdk == 0)
                    new_Skin.Dacia = 1903001;
                  if (DaciaSkinHackSdk == 1) 
                    new_Skin.Dacia = 1903075; //Koenigsegg Gemera (Rainbow)
                     if (DaciaSkinHackSdk == 2) 
                    new_Skin.Dacia = 1903080; //Koenigsegg Gemera (Silver Grey)
                     if (DaciaSkinHackSdk == 3) 
                    new_Skin.Dacia = 1903076; //Koenigsegg Gemera (Drawn)
                     if (DaciaSkinHackSdk == 4) 
                    new_Skin.Dacia = 1903073; //Tesla Roadster (Digital Water) ( DACIA )
                     if (DaciaSkinHackSdk == 5) 
                    new_Skin.Dacia = 1903074; //Koenigsegg Gemera (Silver Gray) ( DACIA )
                     if (DaciaSkinHackSdk == 6) 
                    new_Skin.Dacia = 1903072; //Koenigsegg Gemera (Rainbow) ( DACIA )
                     if (DaciaSkinHackSdk == 7) 
                    new_Skin.Dacia = 1903189; //Lamborghini Estoque Metal Grey ( DACIA )
                     if (DaciaSkinHackSdk == 8) 
                    new_Skin.Dacia = 1903071; //Tesla Roadster (Diamond) ( DACIA )
                     if (DaciaSkinHackSdk == 9) 
                    new_Skin.Dacia = 1903190; //Lamborghini Estoque Metal Grey
                     if (DaciaSkinHackSdk == 10) 
                    new_Skin.Dacia = 1903079; //Lamborghini Estoque Oro
                     if (DaciaSkinHackSdk == 11) 
                    new_Skin.Dacia = 1903191; //Lamborghini Estoque Oro
                     if (DaciaSkinHackSdk == 12) 
                    new_Skin.Dacia = 1903192; //
                     if (DaciaSkinHackSdk == 13) 
                    new_Skin.Dacia = 1903193; //Lamborghini Estoque Oro
                     if (DaciaSkinHackSdk == 14) 
                    new_Skin.Dacia = 1903200; //
                     if (DaciaSkinHackSdk == 15) 
                    new_Skin.Dacia = 1903201; //
                     if (DaciaSkinHackSdk == 16) 
                    new_Skin.Dacia = 1903014; //
                     if (DaciaSkinHackSdk == 17) 
                    new_Skin.Dacia = 1903017; //
                     if (DaciaSkinHackSdk == 18) 
                    new_Skin.Dacia = 1903035; //
                     if (DaciaSkinHackSdk == 19) 
                    new_Skin.Dacia = 1903087; //
                     if (DaciaSkinHackSdk == 20) 
                    new_Skin.Dacia = 1903088; //
                     if (DaciaSkinHackSdk == 21) 
                    new_Skin.Dacia = 1903089; //
                     if (DaciaSkinHackSdk == 22) 
                    new_Skin.Dacia = 1903090; //
                     if (DaciaSkinHackSdk == 23) 
                    new_Skin.Dacia = 1903197; //

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //Mini Bus
  //MiniBusSkinHackSdk
if (MiniBusSkinHackSdk == 0)
    new_Skin.MiniBus = 1904001;
  if (MiniBusSkinHackSdk == 1)
    new_Skin.MiniBus = 1904005;
  if (MiniBusSkinHackSdk == 2)
    new_Skin.MiniBus = 1904006;
if (MiniBusSkinHackSdk == 3)
    new_Skin.MiniBus = 1904007;
if (MiniBusSkinHackSdk == 4)
    new_Skin.MiniBus = 1904008;
if (MiniBusSkinHackSdk == 5)
    new_Skin.MiniBus = 1904009;
if (MiniBusSkinHackSdk == 6)
    new_Skin.MiniBus = 1904010;
if (MiniBusSkinHackSdk == 7)
    new_Skin.MiniBus = 1904011;
if (MiniBusSkinHackSdk == 8)
    new_Skin.MiniBus = 1904012;
if (MiniBusSkinHackSdk == 9)
    new_Skin.MiniBus = 1904013;
if (MiniBusSkinHackSdk == 10)
    new_Skin.MiniBus = 1904014;
if (MiniBusSkinHackSdk == 11)
    new_Skin.MiniBus = 1904015;
if (MiniBusSkinHackSdk == 12)
    new_Skin.MiniBus = 1904004;
    
    
    
                    if (CoupeRPSkinHackSdk == 0)
                    new_Skin.CoupeRP = 1961020; //SSC Tuatara Sky Crane
                    if (CoupeRPSkinHackSdk == 1) 
                    new_Skin.CoupeRP = 1961021; //Lamborghini Aventador (Green) - CoupleRB
                     if (CoupeRPSkinHackSdk == 2) 
                    new_Skin.CoupeRP = 1961024; //Warp Green - CoupleRB
                     if (CoupeRPSkinHackSdk == 3) 
                    new_Skin.CoupeRP = 1961025; //Koenigsegg One:1 Phoenix - CoupleRB
                     if (CoupeRPSkinHackSdk == 4) 
                    new_Skin.CoupeRP = 1961029; //Maserati MC20 Rosso Vincente - CoupleRB
                     if (CoupeRPSkinHackSdk == 5) 
                    new_Skin.CoupeRP = 1961030; //Bugatti La Voiture Noire (Warrior)
                     if (CoupeRPSkinHackSdk == 6) 
                    new_Skin.CoupeRP = 1961031; //Aston Martin Valkyrie (Luminous Diamond)
                     if (CoupeRPSkinHackSdk == 7) 
                    new_Skin.CoupeRP = 1961032; //Koenigsegg One:1 Gilt
                     if (CoupeRPSkinHackSdk == 8) 
                    new_Skin.CoupeRP = 1961033; //Lamborghini Centenario Carbon Fiber
                     if (CoupeRPSkinHackSdk == 9) 
                    new_Skin.CoupeRP = 1961034; //Lamborghini Centenario Carbon Fiber
                     if (CoupeRPSkinHackSdk == 10) 
                    new_Skin.CoupeRP = 1961035; //Koenigsegg Jesko (Rainbow)
                     if (CoupeRPSkinHackSdk == 11) 
                    new_Skin.CoupeRP = 1961051; //Koenigsegg Jesko (Rainbow)
                     if (CoupeRPSkinHackSdk == 12) 
                    new_Skin.CoupeRP = 1961052; //
                     if (CoupeRPSkinHackSdk == 13) 
                    new_Skin.CoupeRP = 1961053; //
                     if (CoupeRPSkinHackSdk == 14) 
                    new_Skin.CoupeRP = 1961054; //
                     if (CoupeRPSkinHackSdk == 15) 
                    new_Skin.CoupeRP = 1961055; //
                     if (CoupeRPSkinHackSdk == 16) 
                    new_Skin.CoupeRP = 1961056; //
                     if (CoupeRPSkinHackSdk == 17) 
                    new_Skin.CoupeRP = 1961057; //
                     if (CoupeRPSkinHackSdk == 18) 
                    new_Skin.CoupeRP = 1961136; //
                     if (CoupeRPSkinHackSdk == 19) 
                    new_Skin.CoupeRP = 1961137; //
                     if (CoupeRPSkinHackSdk == 20) 
                    new_Skin.CoupeRP = 1961138; //
                     if (CoupeRPSkinHackSdk == 21) 
                    new_Skin.CoupeRP = 1961139; //
                     if (CoupeRPSkinHackSdk == 22) 
                    new_Skin.CoupeRP = 1961140; //
                     if (CoupeRPSkinHackSdk == 23) 
                    new_Skin.CoupeRP = 1961141; //
                     if (CoupeRPSkinHackSdk == 24) 
                    new_Skin.CoupeRP = 1961142; //
                     if (CoupeRPSkinHackSdk == 25) 
                    new_Skin.CoupeRP = 1961143; //
                     if (CoupeRPSkinHackSdk == 26) 
                    new_Skin.CoupeRP = 1961150; //
                      if (CoupeRPSkinHackSdk == 27) 
                     new_Skin.CoupeRP = 1961042;// | Bugatti Veyron 16.4 (Gold
                    if (CoupeRPSkinHackSdk == 28) 
                     new_Skin.CoupeRP = 1961043;// | Bugatti Veyron 16.4
                    if (CoupeRPSkinHackSdk == 29) 
                     new_Skin.CoupeRP = 1961044;// | Bugatti La Voiture Noire
                    if (CoupeRPSkinHackSdk == 30) 
                     new_Skin.CoupeRP = 1961045;// | Bugatti La Voiture Noire (Alloy)
                    if (CoupeRPSkinHackSdk == 31) 
                     new_Skin.CoupeRP = 1961046;// | Bugatti La Voiture Noire (Warrior)
                    if (CoupeRPSkinHackSdk == 32) 
                     new_Skin.CoupeRP = 1961047;// | Bugatti La Voiture Noire (Nebula)
                    if (CoupeRPSkinHackSdk == 33) 
                     new_Skin.CoupeRP = 1961147;// | McLaren P1 (Starry Sky)
                    if (CoupeRPSkinHackSdk == 34)
                     new_Skin.CoupeRP = 1961148;// | McLaren P1 (Fantasy Pink)
                    if (CoupeRPSkinHackSdk == 35)
                     new_Skin.CoupeRP = 1961149;// | McLaren P1 (Volcano Yellow)
    


                    
                   if (UAZSkinHackSdk == 0) 
                    new_Skin.UAZ = 1908070; //Robust Universe
                     if (UAZSkinHackSdk == 1) 
                    new_Skin.UAZ = 1908077; //Maserati Levante Neon Urbano
                     if (UAZSkinHackSdk == 2) 
                    new_Skin.UAZ = 1908078; //Maserati Levante Firmamento 
                     if (UAZSkinHackSdk == 3) 
                    new_Skin.UAZ = 1908076; //Maserati Luce Arancione
                     if (UAZSkinHackSdk == 4) 
                    new_Skin.UAZ = 1908075; //Maserati Levante Blu Emozione
                     if (UAZSkinHackSdk == 5) 
                    new_Skin.UAZ = 1908067; //Lamborghini Urus Gialla Inti
                     if (UAZSkinHackSdk == 6) 
                    new_Skin.UAZ = 1908085; //Maserati Levante Blu Emozione
                     if (UAZSkinHackSdk == 7) 
                    new_Skin.UAZ = 1908094; //
                     if (UAZSkinHackSdk == 8) 
                    new_Skin.UAZ = 1908095; //
                     if (UAZSkinHackSdk == 9) 
                    new_Skin.UAZ = 1908188; //
                     if (UAZSkinHackSdk == 10) 
                    new_Skin.UAZ = 1908189; //
                     if (UAZSkinHackSdk == 11) 
                    new_Skin.UAZ = 1908066; //
                     if (UAZSkinHackSdk == 12) 
                    new_Skin.UAZ = 1908189; //
                     if (UAZSkinHackSdk == 13) 
                    new_Skin.UAZ = 1908069; // 
                    
                    
                    
 //BoatSkinHackSdk
    //PG-117
 if (BoatSkinHackSdk == 0)
    new_Skin.Boat = 1911001;
  if (BoatSkinHackSdk == 1)
    new_Skin.Boat = 1911013;
  if (BoatSkinHackSdk == 2)
    new_Skin.Boat = 1911003;
if (BoatSkinHackSdk == 3)
    new_Skin.Boat = 1911004;
if (BoatSkinHackSdk == 4)
    new_Skin.Boat = 1911005;
if (BoatSkinHackSdk == 5)
    new_Skin.Boat = 1911006;
if (BoatSkinHackSdk == 6)
    new_Skin.Boat = 1911007;
if (BoatSkinHackSdk == 7)
    new_Skin.Boat = 1911008;
if (BoatSkinHackSdk == 8)
    new_Skin.Boat = 1911009;
if (BoatSkinHackSdk == 9)
    new_Skin.Boat = 1911010;
if (BoatSkinHackSdk == 10)
    new_Skin.Boat = 1911011;
if (BoatSkinHackSdk == 11)
    new_Skin.Boat = 1911012;


}



int bag111[] = { 501001, 1501001220, 1501001174, 1501001265, 1501001443, 1501001051, 1501001277, 1501001550, 1501001552, 1501001065, 1501001558, 1501001058, 1501001062, 1501001411, 1501001502, 1501001422};
int bag222[] = { 501002, 1501002220, 1501002174, 1501002265, 1501002443, 1501002051, 1501002277, 1501002550, 1501002552, 1501002065, 1501002558, 1501002058, 1501002062, 1501002411, 1501002502, 1501002422};
int bag333[] = { 501003, 1501003220, 1501003174, 1501003265, 1501003443, 1501003051, 1501003277, 1501003550, 1501003552, 1501003065, 1501003558, 1501003058, 1501003062, 1501003411, 1501003502, 1501003422};

int Helmet1[] = { 502001, 1502001028, 1502001014, 1502001023, 1502001065, 1502001031, 1502001033, 1502001069, 1502001261, 1502001272, 1502001183};
int Helmet2[] = { 502002, 1502002028, 1502002014, 1502002023, 1502002065, 1502002031, 1502002033, 1502002069, 1502002261, 1502002272, 1502002183};
int Helmet3[] = { 502003, 1502003028, 1502003014, 1502003023, 1502003065, 1502003031, 1502003033, 1502003069, 1502003261, 1502003272, 1502003183};


int m4v[] = { 101004, 1101004046, 1101004062, 1101004078, 1101004086, 1101004098, 1101004138, 1101004163,1101004201,1101004209,1101004218,1101004226};
//int scar[] = { 101003, 1101003057, 1101003070, 1101003080, 1101003119, 1101003146, 1101003167, 1101003181};
int scar[] = { 101003, 1010031, 1010032, 1010033, 1010034, 1010035, 1010036, 1010037, 1101003057, 1101003070, 1101003080, 1101003119, 1101003146, 1101003167, 1101003181, 1101003195}; //metro
//int akmv[] = { 101001,1101001089, 1101001103, 1101001116, 1101001128, 1101001143, 1101001154, 1101001174,1101001213,1101001231,1101001242};
int akmv[] = { 101001, 1010011, 1010012, 1010013, 1010014, 1010015, 1010016, 101001, 1101001089, 1101001103, 1101001116, 1101001128, 1101001143, 1101001154, 1101001174,1101001213,1101001231,1101001242,1101001249,1101001256,1101001063}; //Metro
//int m7[] = { 101008, 1101008026, 1101008051, 1101008061, 1101008081, 1101008104, 1101008116, 1101008126, 1101008070};
int m7[] = { 101008, 1010081, 1010082, 1010083, 1010084, 1010085, 1010086, 1010087, 1101008026, 1101008051, 1101008061, 1101008081, 1101008104, 1101008116, 1101008126, 1101008070};
//int awm[] = { 103003, 1103003022, 1103003030, 1103003042, 1103003051, 1103003062};
int awm[] = { 103003, 1030031, 1030032, 1030033, 1030034, 1030035, 1030036, 1030037, 1103003022, 1103003030, 1103003042, 1103003051, 1103003062}; //metro
//int amr[] = { 103012, 1103012010};
int amr[] = { 103012, 1030121, 1030122, 1030123, 1030124, 1030125, 1030126, 1030127, 1103012010,1103012019}; //metro
//int mk14[] = { 103007, 1103007020, 1103007028};
int mk14[] = { 103007, 1030071, 1030072, 1030073, 1030074, 1030075, 1030076, 1030077, 1103007020, 1103007028}; //metro
//int mg3[] = { 105010, 1105010008};
int mg3[] = { 105010, 1050101, 1050102, 1050103, 1050104, 1050105, 1050106, 1050107, 1105010008,1105010019};
//int kar[] = { 103001, 1103001060, 1103001079, 1103001101, 1103001145, 1103001160, 1103001179};
int kar[] = { 103001, 1030011, 1030012, 1030013, 1030014, 1030015, 1030016, 1030017, 1103001060, 1103001079, 1103001101, 1103001145, 1103001160, 1103001179}; //metro
//int m24[] = { 103002, 1103002018, 1103002030, 1103002048, 1103002056, 1103002087};
int m24[] = { 103002, 1030021, 1030022, 1030023, 1030023, 1030024, 1030025, 1030026, 1030027, 1103002018, 1103002030, 1103002048, 1103002056, 1103002087}; //Metro 

int mini14[] = { 103006, 1103006030, 1103006046, 1103006058};
int dp[] = { 105002, 1105002018, 1105002035, 1105002058, 1105002063};
int m249[] = { 105001, 1105001020, 1105001034, 1105001048, 1105001054};

//int groza[] = { 101005, 1101005019, 1101005025, 1101005038, 1101005043, 1101005052, 1101005082};
int groza[] = { 101005, 1010051, 1010052, 1010053, 1010054, 1010055, 1010056, 1010057, 1101005019, 1101005025, 1101005038, 1101005043, 1101005052, 1101005082};
//int aug[] = { 101006, 1101006033, 1101006044, 1101006062};
int aug[] = { 101006, 1010061, 1010062, 1010063, 1010064, 1010065, 1010066, 1010067, 1101006033, 1101006044, 1101006062}; //metro
//int m16[] = { 101002, 1101002029, 1101002056, 1101002068, 1101002081, 1101002103};
int m16[] = { 101002, 1010021, 1010022, 1010023, 1010024, 1010025, 1010026, 1010027, 1101002029, 1101002056, 1101002068, 1101002081, 1101002103}; //metro

//int uzi[] = { 102001, 1102001024, 1102001036, 1102001058, 1102001069, 1102001089, 1102001102};
int uzi[] = { 102001, 1020011, 1020012, 1020013, 1020014, 1020015, 1020016, 1020017, 1102001024, 1102001036, 1102001058, 1102001069, 1102001089, 1102001102}; //metro
//int ump[] = { 102002, 1102002043, 1102002061, 1102002090, 1102002117, 1102002124, 1102002129, 1102002136};
int ump[] = { 102002, 1020021, 1020022, 1020023, 1020024, 1020025, 1020026, 1020027, 1102002043, 1102002061, 1102002090, 1102002117, 1102002124, 1102002129, 1102002136}; //Meteo

int thompson[] = {102004, 1102004018, 1102004034};
//int vector2[] = { 102003, 1102003020, 1102003031, 1102003065, 1102003080};
int vector[] = { 102003, 1020031, 1020032, 1020033, 1020034, 1020035, 1020036, 1020037, 1102003020, 1102003031, 1102003065, 1102003080}; //metro
int tommy[] = { 102004, 1102004018, 1102004034};
int bizon[] = { 102005, 1102005007, 1102005020, 1102005041};
//int ace32[] = { 101102, 1101102007, 1101102017};

int ace32[] = { 101102, 1011021, 1011022, 1011023, 1011024, 1011025, 1011026, 1011027, 1101102007, 1101102017,1101102025}; // metro

int pan[] = { 108004, 1108004125, 1108004145, 1108004160, 1108004283, 1108004337, 1108004356, 1108004365, 1108004054, 1108004008};

int m249s[] = { 205009, 1050010351, 1050010412, 1050010482, 1050010542};
int akmmag[] = { 291001,204013,204011,204012,1010010891, 1010011031, 1010011161, 1010011281, 1010011431, 1010011541, 1010011741,1010012131,1010012311,1010012421};
int m7mag[] = { 291008,204013,204011,204012,1010080261, 1010080511, 1010080611, 1010080811, 1010081041, 1010081161, 1010081261};
int scarmag[] = { 291003,204013,204011,204012,1010030571, 1010030701, 1010030801, 1010031191, 1010031461, 1010031671, 1010031811};
int m4mag[] = { 291004,204013,204011,204012,1010040461,1010040611,1010040781,1010040861,1010040981,1010041381,1010041631,1010042011,1010042073,1010042153,1010042206  };

int m4sight[] = { 203008,1010040462,1010040612,1010040782,1010040862,1010040982,1010041382,1010041632,1010042012,1010042083,1010042163,1010042209  };

int m4stock[] = { 205005,1010040463,1010040613,1010040783,1010040863,1010040983,1010041383,1010041633,1010042013,1010042093,1010042173,1010042213  };

int m4stock1[] = { 205002,1010040480,205002,205002,205002,205002,1010041146,1010041579,1010041966,1010042137,1010042173,1010042213,1010042244  };

int m4reddot[] = { 203001,1010040470,203001,203001,203001,203001,1010041128,1010041566,1010041948,1010042029,1010042119,1010042233  };

int m16s[] = { 205007, 1010020292, 1010020562, 1010020682, 1010020812, 1010021032};
int m16mag[] = { 291002,204013,204011,204012, 1010020291, 1010020561, 1010020681, 1010020811, 1010021031};

int SuitX[] = { 403003,1405628,1405870,1405983,1406152,1406311,1406475,1406638,1406872,1406810,1407275,1407276, 1407366 };

int Bag[] = { 501006,501005,501004,501003,501002,501001,1501003220, 1501003174, 1501003051, 1501003443, 1501003265, 1501003321, 1501003277, 1501003550, 1501003552, 1501003061, 1501003058, 1501003062, 1501003422, 1501003503};

int Helmet[] = { 502001,502002,502003,1502003014,1502003028,1502003023,1501002443,1502003031,1502003033,1502003069,1502003261 };


//M416 ONLY
//int M4161[] = { 101004, 1101004046, 1101004062, 1101004078, 1101004086, 1101004098, 1101004138, 1101004163, 1101004201, 1101004209, 1101004218,1101004226};
int M4161[] = { 101004, 1010041, 1010042, 1010043, 1010044, 1010045, 1010046, 1010047, 1101004046, 1101004062, 1101004078, 1101004086, 1101004098, 1101004138, 1101004163, 1101004201, 1101004209, 1101004218,1101004226}; //Metro
int M4162[] = { 291004, 1010040461, 1010040611, 1010040781, 1010040861, 1010040981, 1010041381, 1010041631, 1010042011, 1010042073, 1010042153,1010042206};
int M4163[] = { 203008, 1010040462, 1010040612, 1010040782, 1010040862, 1010040982, 1010041382, 1010041632, 1010042012, 1010042083, 1010042163,1010042209};
int M4164[] = { 205005, 1010040463, 1010040613, 1010040783, 1010040863, 1010040983, 1010041383, 1010041633, 1010042013, 1010042093, 1010042173,1010042213};
int M416flash[] = { 201010, 1010040474, 201010, 201010, 201010, 201010, 1010041136, 201010, 1010041956, 20101000, 1010042128,1010042238};
int M416compe[] = { 201009, 1010040475, 201009, 201009, 201009, 201009, 1010041137, 1010041574, 1010041957, 1010042037, 1010042127,1010042237};
int M416silent[] = { 201011, 1010040476, 201011, 201011, 201011, 201011, 1010041138, 1010041575, 1010041958, 1010042039, 1010042129,1010042239};
//int M416reddot[] = { 203001, 1010040470, 203001, 203001, 203001, 203001, 1010041128, 1010041566, 1010041948, 1010042029, 1010042119};
int M416holo[] = { 203002, 1010040469, 203002, 203002, 203002, 203002, 1010041127, 1010041565, 1010041947, 1010042028, 1010042118,1010042232};
int M416x2[] = { 203003, 1010040468, 203003, 203003, 203003, 203003, 1010041126, 1010041564, 1010041946, 1010042027, 1010042117,1010042231};
int M416x3[] = { 203014, 1010040467, 203014, 203014, 203014, 203014, 1010041125, 1010041560, 1010041945, 1010042026, 1010042116,1010042219};
int M416x4[] = { 203004, 1010040466, 203004, 203004, 203004, 203004, 1010041124, 1010041554, 1010041944, 1010042025, 1010042115,1010042218};
int M416x6[] = { 203015, 1010040481, 203015, 203015, 203015, 203015, 203015, 203015, 1010041967, 1010042024, 1010042114,1010042217};
int M416quickMag[] = { 204012, 1010040472/*1010040471*/, 204012, 204012, 204012, 204012, 1010041134, 1010041568, 1010041949, 1010042034, 1010042124,1010042235};
int M416extendedMag[] = { 204011, 1010040473, 204011, 204011, 204011, 204011, 1010041129, 1010041569, 1010041950, 1010042035, 1010042125,1010042234};
int M416quickNextended[] = { 204013, 1010040473, 204013, 204013, 204013, 204013, 1010041135, 1010041567, 1010041955, 1010042036, 1010042126,1010042236};
int M416stock[] = { 205002, 1010040480, 205002, 205002, 205002, 205002, 1010041146, 1010041579, 1010041966, 1010042047, 1010042137,1010042244};
//int M416verical[] = { 203015, 1010040481, 203015, 203015, 203015, 203015, 1010041145, 1010041578, 1010041965, 1010042046, 1010042136};
int M416angle[] = { 202001, 1010040477, 202001, 202001, 202001, 202001, 1010041139, 1010041576, 1010041959, 1010042044, 1010042134,1010042241};

int M416thumb[] = { 202006, 1010040478, 202006, 202006, 202006, 202006, 202006, 1010041577, 202006, 202006, 1010042135,1010042242};
    
       int MainSuit = 0;
     int MainSuit2 = 0;
     
     int MainBaH = 0;
     int MainBaH2 = 0;
  namespace Active {
  inline int SkinCarDefault = 0;
  inline int SkinCarMod = 0;
  inline int SkinCarNew = 0;
}

void RenderESP(AHUD *HUD)
{
    UCanvas *Canvas = HUD->Canvas;
    if (Canvas) {

        
    updateSkin();
     
    ASTExtraPlayerCharacter *localPlayer = 0;
    ASTExtraPlayerController *localPlayerController = 0;
    
    
    ASTExtraBaseCharacter *STExtraBaseCharacter = 0;
         

    ASTExtraCharacter *Charac = 0;
    FVerifySwitch *VerifySwitch = 0;
    FDistanceContinueHitCheck *DistanceContinueHitCheck = 0;
    FAntiCheatDetailData *AntiCheatDetailData = 0;
    UWeaponAntiCheatComp *WeaponAntiCheatComp = 0;
    AGameNetworkManager *GameNetworkManager = 0;
    UCheatManager *CheatManager = 0;
    UPlayerAntiCheatManager *PlayerAntiCheatManager = 0;
    USTExtraFloatingVehicleMovementComponent *STExtraFloatingVehicleMovementComponent = 0;
    USTExtraHelicopterVehicleMovementComponent *Helicopter = 0;
    ASTExtraShootWeapon *STExtraShootWeapon = 0;
    USceneComponent *SceneComponent = 0;
    UAntiCheatUtils *AntiCheatUtils = 0;
    UGMCheatManager *GMCheatManager = 0;
    UVACTask_AccelerationControl *VACTask_AccelerationControl = 0;
    UWeaponAntiCheatComp *WeaponCheat = 0;
    UVACTask_FlyingVehicle *VACTask_FlyingVehicle = 0;
    UVACTask_FlyingVehicleVelocity *VACTask_FlyingVehicleVelocity = 0;
    UVACTask_FlyingVehicleVelocityChange *VACTask_FlyingVehicleVelocityChange = 0;
    UVACTask_FlyingVehicleZ *VACTask_FlyingVehicleZ = 0;
    UVACTask_SuperSpeed *VACTask_SuperSpeed = 0;
    UVACTask_SuperSpeedAllDir *VACTask_SuperSpeedAllDir = 0;
    UActorComponent *ActorComponent = 0;
    UVACTask_ClientAbsSpeed *VACTask_ClientAbsSpeed = 0;
    FMoveCheatAntiStrategy *MoveCheatAntiStrategy = 0;
    UAssetUserData *AssetUserData = 0;
    USTBuildSystemComponent *STBuildSystemComponent = 0;
    UDefaultAntiCheatComponent *DefaultAntiCheatComponent = 0;
    FMoveCheatAntiStrategy *MoveCheatAntiStrategy2 = 0;

    FClientTimeSpeedCheck *ClientTimeSpeedCheck = 0;
    FRealtimeMoveSpeedCheck *RealtimeMoveSpeedCheck = 0;
    FShovelAntiCheat *ShovelAntiCheat = 0;

        UGameplayStatics *gGameplayStatics = (UGameplayStatics *)UGameplayStatics::StaticClass();
UKismetMathLibrary* UMC = (UKismetMathLibrary*)UKismetMathLibrary::StaticClass();

USlotAvatarComponent* SKIN = (USlotAvatarComponent*)USlotAvatarComponent::StaticClass();
UCharacterAvatarComponent2* SKIN2 = (UCharacterAvatarComponent2*)UCharacterAvatarComponent2::StaticClass();


        auto GWorld = GetWorld();
        if (GWorld) {

            UNetDriver *NetDriver = GWorld->NetDriver;
            if (NetDriver) {
                UNetConnection *ServerConnection = NetDriver->ServerConnection;
                if (ServerConnection) {
                    localPlayerController = (ASTExtraPlayerController *)ServerConnection->PlayerController;
                }
            }

            
            if (localPlayerController)
            {
             
                

 localPlayerController->AntiCheatManagerComp = 0;
    localPlayerController->SpectatorComponent = 0;

localPlayerController->bShouldReportAntiCheat = 0;
 localPlayerController->bUseAntiDataReportFilter = 0;
 localPlayerController->bUseAntiDataReportFilterNew = 0;
 localPlayerController->bUseAntiDataReportFilterCheck = 0;
localPlayerController->LastReportAntiDataTime = 0;
 localPlayerController->bEnableDSErrorLogReport = 0;

                std::vector<ASTExtraPlayerCharacter *> PlayerCharacter;
                GetAllActors(PlayerCharacter);

                for (auto actor = PlayerCharacter.begin(); actor != PlayerCharacter.end(); actor++) {
                    auto Actor = *actor;
                    if (Actor->PlayerKey == ((ASTExtraPlayerController *)localPlayerController)->PlayerKey) {
                        localPlayer = Actor;
                        break;
                    }
                }
                
                
                
                
    if (localPlayer) {
        

                  if(SceneComponent) {
                    SceneComponent->AntiCheatRandValue0 = 0;
                    SceneComponent->AntiCheatRandValue1 = 0;
                    SceneComponent->AntiCheatRandValue2 = 0;
                    SceneComponent->AntiCheatRandValue3 = 0;
                    SceneComponent->AntiCheatRandValue4 = 0;
                    SceneComponent->AntiCheatRandValue5 = 0;
                    SceneComponent->AntiCheatRandValue6 = 0;
                }
                if(localPlayer->MoveAntiCheatComponent) {
                    localPlayer-> MoveAntiCheatComponent = nullptr;
                }
                if(STExtraShootWeapon) {
                    STExtraShootWeapon->AntiCheatComp = nullptr;
                }
                if(localPlayerController) {
                    localPlayerController->AntiCheatManagerComp = 0;
                    localPlayerController->bShouldReportAntiCheat = (bool) 0;
                    localPlayerController->CheatManager = nullptr;
                }
                if(CheatManager) {
                    CheatManager = nullptr;
                }
                if(PlayerAntiCheatManager) {
                    PlayerAntiCheatManager = nullptr;
                    PlayerAntiCheatManager->VehicleSpeedZDeltaTotal = (float) 0;
                    PlayerAntiCheatManager->VehicleSpeedZDeltaOver10Times = (int) 0;
                }
                if(localPlayer->STCharacterMovement) {
                    localPlayer-> STCharacterMovement->bCheatFlying = false;
                }
                if(GameNetworkManager) {
                    GameNetworkManager->bHasStandbyCheatTriggered = false;
                    GameNetworkManager->StandbyRxCheatTime = (float) 0;
                    GameNetworkManager->StandbyTxCheatTime = (float) 0;
                    GameNetworkManager->bMovementTimeDiscrepancyDetection = false;
                }
                if(VerifySwitch) {
                    VerifySwitch = nullptr;
                    VerifySwitch->VerifyFailedCnt = 0;
                }
                if(AntiCheatDetailData){
                    AntiCheatDetailData = nullptr;
                }
                if(DistanceContinueHitCheck) {
                    DistanceContinueHitCheck = nullptr;
                    DistanceContinueHitCheck->MaxCheatTimes = (float) 99999999;
                    DistanceContinueHitCheck->CheckDisSquared = (float) 0;
                }
                if(WeaponAntiCheatComp) {
                    WeaponAntiCheatComp = nullptr;
                    WeaponAntiCheatComp->ShootRateCheckInterval = (float) 0;
                    WeaponAntiCheatComp->ShootRateCheckTag = false;
                    WeaponAntiCheatComp->ShootRateCheckMulCoff = (float) 0;
                    WeaponAntiCheatComp->ShootHitTargetIntervalMulCoff = (float) 0;
                    WeaponAntiCheatComp->ShootTimeInfoCheckClearInterval = (float) 0;
                    WeaponAntiCheatComp->ShootTimeInfoCheckLifeTime = (float) 0;
                    WeaponAntiCheatComp->ShootTimeGunPosBigCircle = (float) 0;
                    WeaponAntiCheatComp->ShootTimeGunPosMaxRightDif = (float) 0;
                    WeaponAntiCheatComp->ShootTimeGunPosMaxRightDifInVehicle = (float) 0;
                    WeaponAntiCheatComp->ShootTimeGunPosMaxRightDif = (float) 0;
                    WeaponAntiCheatComp->ShootTimeGunPosMaxRightDifInVehicle = (float) 0;
                    WeaponAntiCheatComp->MaxClientCapsuleHalfHeight = (int) 9999999;
                    WeaponAntiCheatComp->ShootTimeMuzzleDistThres = (float) 0;
                    WeaponAntiCheatComp->ShootTimeMuzzleZThres = (float) 0;
                    WeaponAntiCheatComp->bVerifyTimeLineSync = false;
                    WeaponAntiCheatComp->TimeLineCheckDnBorder = (float) 0;
                    WeaponAntiCheatComp->TimeLineCheckUpBorder = (float) 0;
                    WeaponAntiCheatComp->ShootTimeConnectionDeltaThres = (float) 0;
                    WeaponAntiCheatComp->bVerifyStartFireTime = false;
                    WeaponAntiCheatComp->MaxShootPassTimeDeltaBetweenSysAndLevel = (float) 0;
                    WeaponAntiCheatComp->TolerateFlyTime = (float) 0;
                    WeaponAntiCheatComp->TolerateFlyDis = (float) 0;
                }
                if(localPlayer->MoveAntiCheatComponent) {
                    localPlayer->  MoveAntiCheatComponent->bUseMoveAntiCheatCheck = false;
                    localPlayer-> MoveAntiCheatComponent->MinMoveAntiCheatCheckIntervel2 = (float) 0;
                 //   localPlayer->  MoveAntiCheatComponent->MaxCheatTimes = (int) 9999999;
                    localPlayer->  MoveAntiCheatComponent->TolerateDistanceFractor = (float) 0;
                    localPlayer->  MoveAntiCheatComponent->MaxPacketLossRate = (float) 99999;
                    localPlayer->  MoveAntiCheatComponent->MinDistanceSqAtStaticColliderCheck = (float) 99999;
                    localPlayer-> MoveAntiCheatComponent->MaxTotalMoveCheatTimes = (int) 999999;
                    localPlayer->  MoveAntiCheatComponent->MinMoveAntiCheatCheckIntervel2 = (float) 0;
                    localPlayer->  MoveAntiCheatComponent->bIsForceAdjustZWhenExceed = false;
                    localPlayer->   MoveAntiCheatComponent->MaxShootPointPassWall = (int) 99999;
                    localPlayer->   MoveAntiCheatComponent->MaxGunPosErrorTimes = (int) 99999;
                 //   localPlayer->   MoveAntiCheatComponent->MaxSkeletonLength = (float) 99999;
                    localPlayer->   MoveAntiCheatComponent->MaxMuzzleHeightTime = (int) 99999;
                    localPlayer->   MoveAntiCheatComponent->MaxLocusFailTime = (int) 99999;
                    localPlayer->  MoveAntiCheatComponent->MaxBulletVictimClientPassWallTimes = (int) 9999999;

                 //   localPlayer-> MoveAntiCheatComponent->MaxShooterDataNumErrorCnt = (int) 9999999;
                    localPlayer->  MoveAntiCheatComponent->MaxJumpHeight = (float) 9999999;
                  //  localPlayer->  MoveAntiCheatComponent->ServerControlMaxThreshold = (int) 0;
                }
                if(MoveCheatAntiStrategy) {
                    MoveCheatAntiStrategy = 0;
                    MoveCheatAntiStrategy->MaxAllowClientSideTimeLag = (float) 99999999;
                    MoveCheatAntiStrategy->CheckTimeSpeedIntervel = (float) 0;
                    MoveCheatAntiStrategy->MaxAllowCheatMoveTimes = (int) 99999999;
                    MoveCheatAntiStrategy->MaxMoveDistanceScaleFactor = (float) 99999999;
                    MoveCheatAntiStrategy->MaxPublishForbidMoveTime = (float) 99999;
                    MoveCheatAntiStrategy->ServerSendPingIntervel = (float) 0;
                    MoveCheatAntiStrategy->MaxMoveSpeedValue = (float) 99999999;
                    MoveCheatAntiStrategy->MaxSpeedSplitNum = (int) 99999999;
                    MoveCheatAntiStrategy->MaxContinuousCheatMoveTimes = (int) 99999999;
                    MoveCheatAntiStrategy->MaxClientSpeed = (int) 99999999;
                }
                if(MoveCheatAntiStrategy2) {
                    MoveCheatAntiStrategy2 = 0;
                    MoveCheatAntiStrategy2->CheckTimeSpeedIntervel = (float) 0;
                    MoveCheatAntiStrategy2->MaxAllowCheatMoveTimes = (int) 99999999;
                    MoveCheatAntiStrategy2->MaxMoveDistanceScaleFactor = (float) 99999999;
                    MoveCheatAntiStrategy2->MaxPublishForbidMoveTime = (float) 99999999;
                    MoveCheatAntiStrategy2->MaxMoveSpeedValue = (float) 99999999;
                    MoveCheatAntiStrategy2->MaxSpeedSplitNum = (int) 99999999;
                }
                if(ShovelAntiCheat){
                    ShovelAntiCheat = 0;
                    ShovelAntiCheat->DataSendInterval = (float) 0;
                    ShovelAntiCheat->DataSampleInterval = (float) 0;
                    ShovelAntiCheat->SampleMoveVelocityTorelate = (float) 0;
                    ShovelAntiCheat->CheatLockTime = (float) 0;
                    ShovelAntiCheat->MaxServerClientDeltaCount = (int) 0;
                }
                if(RealtimeMoveSpeedCheck) {
                    RealtimeMoveSpeedCheck = 0;
                }
                if(ClientTimeSpeedCheck) {
                    ClientTimeSpeedCheck = 0;
                    ClientTimeSpeedCheck->CheckTimeDeltaInterval = (float) 0;
                    ClientTimeSpeedCheck->MaxClientTimeDeltaAheadServer = (float) 99999;
                    ClientTimeSpeedCheck->MaxPublishForbidMoveTime = (float) 99999;
                    ClientTimeSpeedCheck->MaxServerTimeDelta = (float) 0;
                    ClientTimeSpeedCheck->MaxClientAheadServerTotalTime = (float) 0;
                    ClientTimeSpeedCheck->MaxProcessCounterOneFrame = (int) 0;
                }
           
                if( localPlayer->STCharacterMovement){
                    localPlayer-> STCharacterMovement->CheatCheckSumFailed = false;
                    localPlayer->STCharacterMovement->bCheatClientLocation = false;
                    localPlayer-> STCharacterMovement->bUseTimeSpeedAntiCheatCheck = false;
                }
                if(AntiCheatUtils) {
                    AntiCheatUtils = 0;
                }
                if(DefaultAntiCheatComponent) {
                    DefaultAntiCheatComponent = 0;
                }
                if(GMCheatManager) {
                    GMCheatManager = 0;
                }
                if(STBuildSystemComponent) {
                }
                if(VACTask_AccelerationControl) {
                    VACTask_AccelerationControl->MaxAccelerationSpeed = (float) 999999;
                    VACTask_AccelerationControl->CheckInterval = (float) 0;
                }
                if(VACTask_ClientAbsSpeed) {
                    VACTask_ClientAbsSpeed->CheckInterval = (float) 0;
                }
                if(VACTask_FlyingVehicle) {
                    VACTask_FlyingVehicle = 0;
                }
                if(VACTask_FlyingVehicleVelocityChange) {
                    VACTask_FlyingVehicleVelocityChange = 0;
                }
                if(VACTask_FlyingVehicleVelocity) {
                    VACTask_FlyingVehicleVelocity = 0;
                }
                if(VACTask_SuperSpeed) {
                    VACTask_SuperSpeed = 0;
                }
                if(VACTask_SuperSpeedAllDir) {
                    VACTask_SuperSpeedAllDir = 0;
                }
                if(VACTask_FlyingVehicle) {
                    VACTask_FlyingVehicle = 0;
                }
                if(ActorComponent) {
                    ActorComponent = 0;
                }
                if(AssetUserData) {
                    AssetUserData = 0;
                }
            

        
localPlayer->IsEnableReportMrpcsFlow = false;
localPlayer->IsEnableReportGameSetting = false;
localPlayer->IsEnableReportPlayerKillFlow = false;
localPlayer->IsEnableReportPlayerKillFlow = false;
localPlayer->IsEnableReportMrpcsInCircleFlow = false;
localPlayer->IsEnableReportMrpcsInPartCircleFlow = false;
localPlayer->LagCompensationComponent = nullptr;
localPlayer->MoveAntiCheatComponent = nullptr;
        
        
        
                    
               if (Config.MemoryWideView){
     localPlayer->ThirdPersonCameraComponent->SetFieldOfView(Config.MemoryWideViewSize);
   //   localPlayer->ScopeCameraComp->SetFieldOfView(Config.MemoryWideViewSize); //
  //    localPlayer->FPPCameraComp->SetFieldOfView(Config.MemoryWideViewSize - 50);
              }
                    
        
                  
            if (g_LocalController == 0){
  //LOGO
Config.OutfitEnable = false;
   } else {
          
          }


if (localPlayer->AvatarComponent2) {
auto AvatarComp = localPlayer->AvatarComponent2;
FNetAvatarSyncData NetAvatarComp = *(FNetAvatarSyncData*)((uintptr_t)AvatarComp + 0x388);

auto Slotsybc = NetAvatarComp.SlotSyncData;



if (Config.HelmetlAndBag){
    for (int j = 0; j < Slotsybc.Num(); j++) {
 auto& Skin = Slotsybc[j];
 auto ID = Skin.ItemId;

    //Helmet
 if (ID == 502001) {//LV 1
 Skin.ItemId = new_Skin.helmetlv1;
 }
  if (ID == 502002) {//LV 2
 Skin.ItemId = new_Skin.helmetlv2;
 }
 if (ID == 502003) {// LV 3
 Skin.ItemId = new_Skin.helmetlv3;
 }
     //Bag
 if (ID == 501001) {//LV 1
 Skin.ItemId = new_Skin.baglv1;
 }
 if (ID == 501002) {//LV 2
Skin.ItemId = new_Skin.baglv2;
 }
 if (ID == 501003) {// LV 3
 Skin.ItemId = new_Skin.baglv3;
 }


if (MainBaH != Slotsybc[5].ItemId) {
MainBaH = Slotsybc[5].ItemId;
localPlayer->AvatarComponent2->OnRep_BodySlotStateChanged();
}
if (MainBaH2 != Slotsybc[6].ItemId) {
MainBaH2 = Slotsybc[6].ItemId;
localPlayer->AvatarComponent2->OnRep_BodySlotStateChanged();
}

 }}

//if (Config.OutfitEnable) {


if (SuitSkinHackHudSdk == 1) {
Slotsybc[2].ItemId = 1405870; //Blood Raven X-Suit (6-Star)
} else if (SuitSkinHackHudSdk == 2) {
Slotsybc[2].ItemId = 1405628; //Golden Pharaoh X-Suit (6-Star)
} else if (SuitSkinHackHudSdk == 3) {
Slotsybc[2].ItemId = 1406469; //Golden Pharaoh X-Suit (7-Star)
} else if (SuitSkinHackHudSdk == 4) {
Slotsybc[2].ItemId = 1406152; //Avalanche X-Suit (6-Star)
} else if (SuitSkinHackHudSdk == 5) {
Slotsybc[2].ItemId = 1406475; //Iridescence X-Suit (6-Star)
} else if (SuitSkinHackHudSdk == 6) {
Slotsybc[2].ItemId = 1405983; //Poseidon X-Suit (6-Star)
} else if (SuitSkinHackHudSdk == 7) {
Slotsybc[2].ItemId = 1406638; //Arcane Jester X-Suit (6-Star)
} else if (SuitSkinHackHudSdk == 8) {
Slotsybc[2].ItemId = 1406311;//Silvanus X-Suit (6-Star)
Slotsybc[4].ItemId = 1403414;//Silvanus X-Suit Mask
} else if (SuitSkinHackHudSdk == 9) {
Slotsybc[2].ItemId = 1406971; //Marmoris X-Suit (7-Star)
} else if (SuitSkinHackHudSdk == 10) { 
Slotsybc[2].ItemId = 1407103; //Fiore X-Suit
} else if (SuitSkinHackHudSdk == 11) { 
Slotsybc[2].ItemId = 1407259; //Ignis X-Suit (7-Star)
} else if (SuitSkinHackHudSdk == 12) { 
Slotsybc[2].ItemId = 1406872; // Stygian Liege X-Suit (6-Star) 
} else if (SuitSkinHackHudSdk == 13) { 
Slotsybc[2].ItemId = 1407366; //Galadria X-Suit (7-Star)
} 

///new
if (SpSuitSkinHackHudSdk == 1) { 
Slotsybc[2].ItemId = 1400782;//Glacier Set
} else if (SpSuitSkinHackHudSdk == 2) { 
Slotsybc[2].ItemId = 1400119;//Wanderer Outfit
} else if (SpSuitSkinHackHudSdk == 3) { 
Slotsybc[2].ItemId = 1400117;//FireMan Set
} else if (SpSuitSkinHackHudSdk == 4) { 
Slotsybc[2].ItemId = 1400693;//Vampire Set
} else if (SpSuitSkinHackHudSdk == 5) { 
Slotsybc[2].ItemId = 1405092;//The Fool Set
Slotsybc[4].ItemId = 1403028;//The Fool Mask
} else if (SpSuitSkinHackHudSdk == 6) { 
Slotsybc[2].ItemId = 1405090;//Smooth Hitman Set (Cat) {
} else if (SpSuitSkinHackHudSdk == 8) { 
Slotsybc[2].ItemId = 1405482;//Anniversary Unicorn Set
} else if (SpSuitSkinHackHudSdk == 5) { 
Slotsybc[2].ItemId = 1405583;//Dazzling Youth Set
} else if (SpSuitSkinHackHudSdk == 9) { 
Slotsybc[2].ItemId = 1405593;//Red Commander Set
} else if (SpSuitSkinHackHudSdk == 10) { 
Slotsybc[2].ItemId = 1405629;//Dark Widow Set
} else if (SpSuitSkinHackHudSdk == 11) { 
Slotsybc[2].ItemId = 1405582;//Violet Halo Set
} else if (SpSuitSkinHackHudSdk == 12) { 
Slotsybc[2].ItemId = 1405623; //Yellow Mummy
} else if (SpSuitSkinHackHudSdk == 13) { 
Slotsybc[2].ItemId = 1400687; //White Mummy
} else if (SpSuitSkinHackHudSdk == 14) { 
Slotsybc[2].ItemId = 1405102; //Golden Trigger
} else if (SpSuitSkinHackHudSdk == 15) { 
Slotsybc[2].ItemId = 1405207; //Ryan Set
} else if (SpSuitSkinHackHudSdk == 16) { 
Slotsybc[2].ItemId = 1406398; //Flamewraith Set
} else if (SpSuitSkinHackHudSdk == 17) { 
Slotsybc[2].ItemId = 1406742; //Silver Guru - Set
}else if (SpSuitSkinHackHudSdk == 18) { 
Slotsybc[2].ItemId = 1407225; //luminous Set
}else if (SpSuitSkinHackHudSdk == 19) { 
Slotsybc[2].ItemId = 1407180; //
} else if (SpSuitSkinHackHudSdk == 20) { 
Slotsybc[2].ItemId = 1407800; //
} else if (SpSuitSkinHackHudSdk == 21) { 
Slotsybc[2].ItemId = 1407145; //
} else if (SpSuitSkinHackHudSdk == 22) { 
Slotsybc[2].ItemId = 1407159; //
} else if (SpSuitSkinHackHudSdk == 23) { 
Slotsybc[2].ItemId = 1407187; //
} else if (SpSuitSkinHackHudSdk == 24) { 
Slotsybc[2].ItemId = 1407229; //
} else if (SpSuitSkinHackHudSdk == 25) { 
Slotsybc[2].ItemId = 1407240; //
} else if (SpSuitSkinHackHudSdk == 26) { 
Slotsybc[2].ItemId = 1407222; //
} else if (SpSuitSkinHackHudSdk == 27) { 
Slotsybc[2].ItemId = 1407085; // Dream Striker Set 
} else if (SpSuitSkinHackHudSdk == 28) { 
Slotsybc[2].ItemId = 1406390; // Dream Striker Set 
}



if (OfSuitSkinHackHudSdk == 1) { 
Slotsybc[2].ItemId = 1407247; //
} else if (OfSuitSkinHackHudSdk == 2) { 
Slotsybc[2].ItemId = 1407186; //
} else if (OfSuitSkinHackHudSdk == 3) { 
Slotsybc[2].ItemId = 1407239; //
} else if (OfSuitSkinHackHudSdk == 4) { 
Slotsybc[2].ItemId = 1407232; //
} else if (OfSuitSkinHackHudSdk == 5) { 
Slotsybc[2].ItemId = 1407250; //
} else if (OfSuitSkinHackHudSdk == 6) { 
Slotsybc[2].ItemId = 1416657; //
} else if (OfSuitSkinHackHudSdk == 7) { 
Slotsybc[2].ItemId = 1406660; //
} else if (OfSuitSkinHackHudSdk == 8) { 
Slotsybc[2].ItemId = 1405186; //
} else if (OfSuitSkinHackHudSdk == 9) { 
Slotsybc[2].ItemId = 1405015; //
} else if (OfSuitSkinHackHudSdk == 10) { 
Slotsybc[2].ItemId = 1407160; //
} else if (OfSuitSkinHackHudSdk == 11) { 
Slotsybc[2].ItemId = 1407161; //
} else if (OfSuitSkinHackHudSdk == 12) { 
Slotsybc[2].ItemId = 1400690; //
} else if (OfSuitSkinHackHudSdk == 13) { 
Slotsybc[2].ItemId = 1405005; //
} else if (OfSuitSkinHackHudSdk == 14) { 
Slotsybc[2].ItemId = 1400692; //
} else if (OfSuitSkinHackHudSdk == 15) { 
Slotsybc[2].ItemId = 1400678; //
} else if (OfSuitSkinHackHudSdk == 16) { 
Slotsybc[2].ItemId = 1406658; //
} else if (OfSuitSkinHackHudSdk == 17) { 
Slotsybc[2].ItemId = 1405013; //
} else if (OfSuitSkinHackHudSdk == 18) { 
Slotsybc[2].ItemId = 1405004; //
} else if (OfSuitSkinHackHudSdk == 19) { 
Slotsybc[2].ItemId = 1400668; // Avant Garde Set
} else if (OfSuitSkinHackHudSdk == 20) { 
Slotsybc[2].ItemId = 1406555; // Nether Visage Set
} else if (OfSuitSkinHackHudSdk == 21) { 
Slotsybc[2].ItemId = 1406482; // Bramble Overlor
//Slotsybc[3].ItemId = 1402281; // Bramble Overlor 
} else if (OfSuitSkinHackHudSdk == 22) { 
Slotsybc[2].ItemId = 1406483; // Lightning Nebula 
} else if (OfSuitSkinHackHudSdk == 23) { 
Slotsybc[2].ItemId = 1407094; // Midnight Muse Set
} else if (OfSuitSkinHackHudSdk == 24) { 
Slotsybc[2].ItemId = 1400268; // The Skulls 
} else if (OfSuitSkinHackHudSdk == 25) { 
Slotsybc[2].ItemId = 1407079; // The Fool's Delight Set
} else if (OfSuitSkinHackHudSdk == 26) { 
Slotsybc[2].ItemId = 1406891; // Psychophage Set
} else if (OfSuitSkinHackHudSdk == 27) { 
Slotsybc[2].ItemId = 1406154; // Draconic Paladin Set 
} else if (OfSuitSkinHackHudSdk == 28) { 
Slotsybc[2].ItemId = 1407107; // Winter Highness Set 
}



if (TdmSuitSkinHackHudSdk == 1) {
Slotsybc[2].ItemId = 1406673; //Sweet Bunny Set
} else if (TdmSuitSkinHackHudSdk == 2) {
Slotsybc[2].ItemId = 1406728; //Bruce Lee Kung Fu set
} else if (TdmSuitSkinHackHudSdk == 3) {
Slotsybc[2].ItemId = 1406817; //Sacred Maiden Set
} else if (TdmSuitSkinHackHudSdk == 4) {
Slotsybc[2].ItemId = 1405132; //Forest Elf Set 
} else if (TdmSuitSkinHackHudSdk == 5) {
Slotsybc[2].ItemId = 1407151; // Line Friends LEONARD Raincoat Set
} else if (TdmSuitSkinHackHudSdk == 6) {
Slotsybc[2].ItemId = 1407150; // LINE FRIENDS CHOCO Dress Set 
} else if (TdmSuitSkinHackHudSdk == 7) {
Slotsybc[2].ItemId = 1407484; //Sushi Fantasy Set
} else if (TdmSuitSkinHackHudSdk == 8) {
Slotsybc[2].ItemId = 1404049; //BAPE X PUBGM CAMO Hoodie
Slotsybc[1].ItemId = 1404050; //BAPE X PUBGM CAMO Shorts
Slotsybc[3].ItemId = 1404051; //BAPE X PUBGM CAMO Shoes
} else if (TdmSuitSkinHackHudSdk == 9) {
Slotsybc[2].ItemId = 1400569; // BAPE MIX CAMO HOODIE
Slotsybc[1].ItemId = 1400650; // BAPE MIX CAMO SHORTS
Slotsybc[7].ItemId = 1400651; // BAPE STA MID
} else if (TdmSuitSkinHackHudSdk == 10) {
Slotsybc[2].ItemId = 1400324; // Urban Walker Top
Slotsybc[1].ItemId = 1404191; // Urban Walker Pants
Slotsybc[3].ItemId = 1404192; // Urban Walker Shoes
}else if (TdmSuitSkinHackHudSdk == 11) {
Slotsybc[2].ItemId = 1405334; // Masked Psychic Robe set
Slotsybc[3].ItemId = 1402280; // Masked Psychic Hat
}else if (TdmSuitSkinHackHudSdk == 12) {
Slotsybc[2].ItemId = 1407277; // Inferno Fiend Set
}else if (TdmSuitSkinHackHudSdk == 13) {
Slotsybc[2].ItemId = 1407307; // Dark Arts Gentleman Set
}else if (TdmSuitSkinHackHudSdk == 14) {
Slotsybc[2].ItemId = 1405749; // Leopard Suit Outfit 
}else if (TdmSuitSkinHackHudSdk == 15) {
Slotsybc[2].ItemId = 1404133; // Dark Gold Top
Slotsybc[4].ItemId = 1403660; // Shinobi Spirit mask 
Slotsybc[1].ItemId = 1404137; // Glinting Dancer Pants 
}

/////////////////////////////////////////////////////////////////??????

                    if (SpSuitSkinHackHudSdk == 5)
                    emote1 = 12209001; //Emote Upgrade Wand
                    if (SpSuitSkinHackHudSdk == 51)
                    emote2 = 12212501; //GACKT Exclusive Emote
             
/////////////////////////////////////////////////////////////////??????

                    if (SuitSkinHackHudSdk == 1)
                    emote1 = 12209001; //blood raven x suit
                    if (SuitSkinHackHudSdk == 2)
                    emote1 = 12201401; //Golden Pharaoh X-Suit
                    if (SuitSkinHackHudSdk == 3)
                    emote1 = 12219029; //Avalanche
                    if (SuitSkinHackHudSdk == 4)
                    emote1 = 1501002443; //Irresidence
                    if (SuitSkinHackHudSdk == 5)
                    emote1 = 12219324; //Poseidon
                    if (SuitSkinHackHudSdk == 6)
                    emote1 = 1502001033; //Arcane Jester X-suit
                    if (SuitSkinHackHudSdk == 7)
                    emote1 = 12219803; //Silvanus X-Suit
                    if (SuitSkinHackHudSdk == 8)
                    emote1 = 12219627; 
                    if (SuitSkinHackHudSdk == 11)
                    emote1 = 12209001; 
    

                    if (SuitSkinHackHudSdk == 1)
                    emote2 = 12212501; //blood raven x suit
                    if (SuitSkinHackHudSdk == 2)
                    emote2 = 12219211; //Golden Pharaoh X-Suit
                    if (SuitSkinHackHudSdk == 3)
                    emote2 = 12219234; //Avalanche
                    if (SuitSkinHackHudSdk == 4)
                    emote2 = 1501002443; //Irresidence
                    if (SuitSkinHackHudSdk == 5)
                    emote2 = 12219330; //Poseidon
                    if (SuitSkinHackHudSdk == 6)
                    emote2 = 1502002033; //Arcane Jester X-suit
                    if (SuitSkinHackHudSdk == 7)
                    emote2 = 12219801; //Silvanus X-Suit
                    if (SuitSkinHackHudSdk == 8)
                    emote2 = 12219629; 
                    if (SuitSkinHackHudSdk == 11)
                    emote2 = 12208701; 

                    if (SuitSkinHackHudSdk == 1)
                    emote3 = 12219082; //blood raven x suit
                    if (SuitSkinHackHudSdk == 2)
                    emote3 = 12219049; //Golden Pharaoh X-Suit
                    if (SuitSkinHackHudSdk == 3)
                    emote3 = 12219233; //Avalanche
                    if (SuitSkinHackHudSdk == 4)
                    emote3 = 12219331; //Irresidence
                    if (SuitSkinHackHudSdk == 5)
                    emote3 = 12219235; //Poseidon
                    if (SuitSkinHackHudSdk == 6)
                    emote3 = 1502003033; //Arcane Jester X-suit
                    if (SuitSkinHackHudSdk == 7)
                    emote3 = 12219805; //Silvanus X-Suit
                    if (SuitSkinHackHudSdk == 8)
                    emote3 = 12219631; 
                    if (SuitSkinHackHudSdk == 11)
                    emote3 = 12219611; 
                    
//////////////////

             
  


if (MainSuit != Slotsybc[2].ItemId) {
MainSuit = Slotsybc[2].ItemId;
//localPlayer->AvatarComponent2->OnRep_BodySlotStateChanged();


    localPlayer->AvatarComponent2->OnRep_BodySlotStateChanged();
  //localPlayerController->BackpackComponent->OnRep_ItemListNet();
}

//}

}

if (Config.SkinEnable){
      if (localPlayer->WeaponManagerComponent != 0) {
     if (localPlayer->WeaponManagerComponent->CurrentWeaponReplicated != 0 ) {
    int weapowep = localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponID();
    auto currentTime = std::chrono::steady_clock::now();
    auto landchud = localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->synData;
    auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastWeaponChangeTime).count();
         if (timeDiff > 1000) {
         for (int j = 0; j < landchud.Num(); j++) {
             auto& weaponInfo = landchud[j];
             auto weaponid = weaponInfo.DefineID.TypeSpecificID;
             if (weaponid != 0)
             {
             
  if (weapowep == 101001 || weapowep == 1010011 || weapowep == 1010012 || weapowep == 1010013 || weapowep == 1010014 || weapowep == 1010015 || weapowep == 1010016 || weapowep == 1010017){
                 for (int i = 0; i < sizeof(akmv) / sizeof(akmv[0]); i++) {
                 if (weaponid == akmv[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.AKM;
                     break;
                  }
                 }
                 for (int i = 0; i < sizeof(akmmag) / sizeof(akmmag[0]); i++) {
                 if (weaponid == akmmag[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.AKM_Mag;
                     break;
                  }
                 }
                }
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
              if (weapowep == 103001 || weapowep == 1030011 || weapowep == 1030012 || weapowep == 1030013 || weapowep == 1030014 || weapowep == 1030015 || weapowep == 1030016 || weapowep == 1030017){
                 for (int i = 0; i < sizeof(kar) / sizeof(kar[0]); i++) {
                 if (weaponid == kar[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.K98;
                     break;
                  }
                 }
                }
                if (weapowep == 103002 || weapowep == 1030021 || weapowep == 1030022 || weapowep == 1030023 || weapowep == 1030024 || weapowep == 1030025 || weapowep == 1030026 || weapowep == 1030027){
                 for (int i = 0; i < sizeof(m24) / sizeof(m24[0]); i++) {
                 if (weaponid == m24[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M24;
                     break;
                  }
                 }
                }
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (weapowep == 103003 || weapowep == 1030031 || weapowep == 1030032 || weapowep == 1030033 || weapowep == 1030034 || weapowep == 1030035 || weapowep == 1030036 || weapowep == 1030037){
                 for (int i = 0; i < sizeof(awm) / sizeof(awm[0]); i++) {
                 if (weaponid == awm[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.AWM;
                     break;
                  }
                 }
                }
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
              if (weapowep == 103012 || weapowep == 1030121 || weapowep == 1030122 || weapowep == 1030123 || weapowep == 1030124 || weapowep == 1030125 || weapowep == 1030126 || weapowep == 1030127){
                 for (int i = 0; i < sizeof(amr) / sizeof(amr[0]); i++) {
                 if (weaponid == amr[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.AMR;
                     break;
                  }
                 }
                }
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (weapowep == 103007 || weapowep == 1030071 || weapowep == 1030072 || weapowep == 1030073 || weapowep == 1030074 || weapowep == 1030075 || weapowep == 1030076 || weapowep == 1030077){
                 for (int i = 0; i < sizeof(mk14) / sizeof(mk14[0]); i++) {
                 if (weaponid == mk14[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.MK14;
                     break;
                  }
                 }
                }
                
                
        if (weapowep == 105010 || weapowep == 1050101 || weapowep == 1050102 || weapowep == 1050103 || weapowep == 1050104 || weapowep == 1050105 || weapowep == 1050106 || weapowep == 1050107){
                 for (int i = 0; i < sizeof(mg3) / sizeof(mg3[0]); i++) {
                 if (weaponid == mg3[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.MG3;
                     break;
                  }
                 }
                }
                
              /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 if (weapowep == 101102 || weapowep == 1011021 || weapowep == 1011022 || weapowep == 1011023 || weapowep == 1011024 || weapowep == 1011025 || weapowep == 1011026 || weapowep == 1011027){
                 for (int i = 0; i < sizeof(ace32) / sizeof(ace32[0]); i++) {
                 if (weaponid == ace32[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.ACE32;
                     break;
                  }
                 }
        }
              ////////////////////////////////////////////////////////////////////////////////////////////////
              /*
               if (weapowep == 101007 || weapowep == 1010071 || weapowep == 1010072 || weapowep == 1010073 || weapowep == 1010074 || weapowep == 1010075 || weapowep == 1010076 || weapowep == 1010077){
                 for (int i = 0; i < sizeof(qbz) / sizeof(qbz[0]); i++) {
                 if (weaponid == qbz[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Qbz;
                     break;
                  }
                 }
        }
        
        */
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (weapowep == 102003 || weapowep == 1020031 || weapowep == 1020032 || weapowep == 1020033 || weapowep == 1020034 || weapowep == 1020035 || weapowep == 1020036 || weapowep == 1020037){
                 for (int i = 0; i < sizeof(vector) / sizeof(vector[0]); i++) {
                 if (weaponid == vector[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Vector;
                     break;
                  }
                 }
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 102002 || weapowep == 1020021 || weapowep == 1020022 || weapowep == 1020023 || weapowep == 1020024 || weapowep == 1020025 || weapowep == 1020026 || weapowep == 1020027){        
          
                 for (int i = 0; i < sizeof(ump) / sizeof(ump[0]); i++) {
                 if (weaponid == ump[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.UMP;
                     break;
                  }
                 }
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                     if (weapowep == 102001 || weapowep == 1020011 || weapowep == 1020012 || weapowep == 1020013 || weapowep == 1020014 || weapowep == 1020015 || weapowep == 1020016 || weapowep == 1020017){        
              
                 for (int i = 0; i < sizeof(uzi) / sizeof(uzi[0]); i++) {
                 if (weaponid == uzi[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.UZI;
                     break;
                  }
                 }
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                
                     if (weapowep == 102005 || weapowep == 1020051 || weapowep == 1020052 || weapowep == 1020053 || weapowep == 1020054 || weapowep == 1020055 || weapowep == 1020056 || weapowep == 1020057){        
              
                 for (int i = 0; i < sizeof(bizon) / sizeof(bizon[0]); i++) {
                 if (weaponid == bizon[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Bizon;
                     break;
                  }
                 }
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                
                          if (weapowep == 101002 || weapowep == 1010021 || weapowep == 1010022 || weapowep == 1010023 || weapowep == 1010024 || weapowep == 1010025 || weapowep == 1010026 || weapowep == 1010027){        
             
                 for (int i = 0; i < sizeof(m16) / sizeof(m16[0]); i++) {
                 if (weaponid == m16[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M16A4;
                     break;
                  }
                 }
                 for (int i = 0; i < sizeof(m16s) / sizeof(m16s[0]); i++) {
                 if (weaponid == m16s[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M16A4_Stock;
                     break;
                  }
                 }
                 for (int i = 0; i < sizeof(m16mag) / sizeof(m16mag[0]); i++) {
                 if (weaponid == m16mag[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M16A4_Mag;
                     break;
                  }
                 }
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (weapowep == 101006 || weapowep == 1010061 || weapowep == 1010062 || weapowep == 1010063 || weapowep == 1010064 || weapowep == 1010065 || weapowep == 1010066 || weapowep == 1010067){        
                  
                 for (int i = 0; i < sizeof(aug) / sizeof(aug[0]); i++) {
                 if (weaponid == aug[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.AUG;
                     break;
                  }
                 }
                }
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
              
         if (weapowep == 101005 || weapowep == 1010051 || weapowep == 1010052 || weapowep == 1010053 || weapowep == 1010054 || weapowep == 1010055 || weapowep == 1010056 || weapowep == 1010057){        
          
                 for (int i = 0; i < sizeof(groza) / sizeof(groza[0]); i++) {
                 if (weaponid == groza[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Groza;
                     break;
                  }
                 }
                }
                
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
           
                if (weapowep == 105002){
                 for (int i = 0; i < sizeof(dp) / sizeof(dp[0]); i++) {
                 if (weaponid == dp[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.DP28;
                     break;
                  }
                 }
                }
                if (weapowep == 105001){
                 for (int i = 0; i < sizeof(m249) / sizeof(m249[0]); i++) {
                 if (weaponid == m249[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M249;
                     break;
                  }
                 }
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
               /*
           if (weapowep == 102105 || weapowep == 1021051 || weapowep == 1021052 || weapowep == 1021053 || weapowep == 1021054 || weapowep == 1021055 || weapowep == 1021056 || weapowep == 1021057){
           
                 for (int i = 0; i < sizeof(p90) / sizeof(p90[0]); i++) {
                 if (weaponid == p90[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.P90;
                     break;
                  }
                 }
                }
/
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
                /
           if (weapowep == 102004 || weapowep == 1020041 || weapowep == 1020042 || weapowep == 1020043 || weapowep == 1020044 || weapowep == 1020045 || weapowep == 1020046 || weapowep == 1020047){
           
                 for (int i = 0; i < sizeof(tommy) / sizeof(tommy[0]); i++) {
                 if (weaponid == tommy[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Tommy;
                     break;
                  }
                 }
                }/
*/
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
                
                 
     if (weapowep == 101003 || weapowep == 1010031 || weapowep == 1010032 || weapowep == 1010033 || weapowep == 1010034 || weapowep == 1010035 || weapowep == 1010036 || weapowep == 1010037){
             
                 for (int i = 0; i < sizeof(scar) / sizeof(scar[0]); i++) {
                 if (weaponid == scar[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Scar;
                     break;
                  }
                 }
                 for (int i = 0; i < sizeof(scarmag) / sizeof(scarmag[0]); i++) {
                 if (weaponid == scarmag[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Scar_Mag;
                     break;
                  }
                 }
                }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            if (weapowep == 101008 || weapowep == 1010081 || weapowep == 1010082 || weapowep == 1010083 || weapowep == 1010084 || weapowep == 1010085 || weapowep == 1010086 || weapowep == 1010087){
              
                 for (int i = 0; i < sizeof(m7) / sizeof(m7[0]); i++) {
                 if (weaponid == m7[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M762;
                     break;
                  }
                 }
                 for (int i = 0; i < sizeof(m7mag) / sizeof(m7mag[0]); i++) {
                 if (weaponid == m7mag[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M762_Mag;
                     break;
                  }
                 }
                }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        if (weapowep == 101004 ||weapowep == 1010041 ||weapowep == 1010042 ||weapowep == 1010043 ||weapowep == 1010044 || weapowep == 1010045 || weapowep == 1010046 || weapowep == 1010047 ) {
  for (int i = 0; i < sizeof(M4161) / sizeof(M4161[0]); i++) {
                 if (weaponid == M4161[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_1;
                     break;
                  }
                 }
                 
                 for (int i = 0; i < sizeof(M4162) / sizeof(M4162[0]); i++) {
                 if (weaponid == M4162[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_2;
                     break;
                  }
                 }
                 
                 for (int i = 0; i < sizeof(M4163) / sizeof(M4163[0]); i++) {
                 if (weaponid == M4163[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_3;
                     break;
                  }
                  }
                 
                 for (int i = 0; i < sizeof(m4stock) / sizeof(m4stock[0]); i++) {
                 if (weaponid == m4stock[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_4;
                     break;
                  }
                 }
                
                 for (int i = 0; i < sizeof(M416flash) / sizeof(M416flash[0]); i++) {
                 if (weaponid == M416flash[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_flash;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416compe) / sizeof(M416compe[0]); i++) {
                 if (weaponid == M416compe[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_compe;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416silent) / sizeof(M416silent[0]); i++) {
                 if (weaponid == M416silent[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_silent;
                 break;
                 }
                 }
                 /*
                 for (int i = 0; i < sizeof(M416_reddot) / sizeof(M416_reddot[0]); i++) {
                 if (weaponid == M416_reddot[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_reddot;
                 break;
                 }
                 }
                 */
                 for (int i = 0; i < sizeof(M416holo) / sizeof(M416holo[0]); i++) {
                 if (weaponid == M416holo[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_holo;
                 break;
                 }
                 }
                
                 for (int i = 0; i < sizeof(M416x2) / sizeof(M416x2[0]); i++) {
                 if (weaponid == M416x2[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_x2;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416x3) / sizeof(M416x3[0]); i++) {
                 if (weaponid == M416x3[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_x3;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416x4) / sizeof(M416x4[0]); i++) {
                 if (weaponid == M416x4[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_x4;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416x6) / sizeof(M416x6[0]); i++) {
                 if (weaponid == M416x6[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_x6;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416quickMag) / sizeof(M416quickMag[0]); i++) {
                 if (weaponid == M416quickMag[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_quickMag;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416extendedMag) / sizeof(M416extendedMag[0]); i++) {
                 if (weaponid == M416extendedMag[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_extendedMag;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416quickNextended) / sizeof(M416quickNextended[0]); i++) {
                 if (weaponid == M416quickNextended[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_quickNextended;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416stock) / sizeof(M416stock[0]); i++) {
                 if (weaponid == M416stock[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_stock;
                 break;
                 }
                 }
                 for (int i = 0; i < sizeof(M416angle) / sizeof(M416angle[0]); i++) {
                 if (weaponid == M416angle[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_angle;
                 break;
                 }
                 }

                 for (int i = 0; i < sizeof(M416thumb) / sizeof(M416thumb[0]); i++) {
                 if (weaponid == M416thumb[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_thumb;
                 break;
                 }
                 }
                 }
   
                }
                 localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->DelayHandleAvatarMeshChanged();
                 lastWeaponChangeTime = currentTime;
             }
         }
     }
 }
}
        
        

        if (Config.CarMod){

            if (localPlayer -> CurrentVehicle) {

                if (localPlayer -> CurrentVehicle -> VehicleAvatar) {

                  std::string SkinIDStr = std::to_string((int) localPlayer -> CurrentVehicle -> VehicleAvatar -> GetDefaultAvatarID());

                  Active::SkinCarDefault = localPlayer -> CurrentVehicle -> GetAvatarID();

                  

                  if (strstr(SkinIDStr.c_str(), "1901")) {

                    Active::SkinCarMod = new_Skin.Moto;

                    Active::SkinCarNew = true;

                  } else if (strstr(SkinIDStr.c_str(), "1903")) {

                    Active::SkinCarMod = new_Skin.Dacia;

                    Active::SkinCarNew = true;

                  } else if (strstr(SkinIDStr.c_str(), "1911")) {

                    Active::SkinCarMod = new_Skin.Boat;

                    Active::SkinCarNew = true;

                  } else if (strstr(SkinIDStr.c_str(), "1904")) {

                    Active::SkinCarMod = new_Skin.MiniBus;

                    Active::SkinCarNew = true;

                  } else if (strstr(SkinIDStr.c_str(), "1914")) {

                    Active::SkinCarMod = new_Skin.Mirado;

                    Active::SkinCarNew = true;

                  } else if (strstr(SkinIDStr.c_str(), "1915")) {

                    Active::SkinCarMod = new_Skin.Mirado;

                    Active::SkinCarNew = true;

                  } else if (strstr(SkinIDStr.c_str(), "1907")) {

                    Active::SkinCarMod = new_Skin.Buggy;

                    Active::SkinCarNew = true;

                }else if (strstr(SkinIDStr.c_str(), "1961")) {

                    Active::SkinCarMod = new_Skin.CoupeRP;

                    Active::SkinCarNew = true;

                  } else if (strstr(SkinIDStr.c_str(), "1953")) {

                    Active::SkinCarMod = new_Skin.Bigfoot;

                    Active::SkinCarNew = true;

                  } else if (strstr(SkinIDStr.c_str(), "1908")) {

                    Active::SkinCarMod = new_Skin.UAZ;

                    Active::SkinCarNew = true;

                  } else Active::SkinCarNew = false;

                  if (Active::SkinCarDefault != Active::SkinCarMod && Active::SkinCarNew) {

                    

                    localPlayer -> CurrentVehicle -> VehicleAvatar -> ChangeItemAvatar(Active::SkinCarMod, true);

                  }

                }

              }

            }

      if (!g_LocalController || !g_LocalController->BackpackComponent) return;

      auto Backpack = (UBackpackComponent*)g_LocalController->BackpackComponent;

      if (!Backpack) return;

      auto& bag = Backpack->ItemListNet.IncArray;

      bool NeedRefreshBack = false;

      for (int j = 0; j < bag.Num(); j++) {

          if (!bag.IsValidIndex(j)) continue;

          int ID = bag[j].Unit.DefineID.TypeSpecificID;

          auto& AdditionalData = bag[j].Unit.AdditionalData;

          bool bFoundAvatar = false;

          int NewSkinID = -1;

          

          switch (ID) {

              case 101001: NewSkinID = new_Skin.AKM; break;

              case 101002: NewSkinID = new_Skin.M16A4; break;

              case 101003: NewSkinID = new_Skin.Scar; break;

              case 101004: NewSkinID = new_Skin.M416_1; break;

              case 101005: NewSkinID = new_Skin.Groza; break;

              case 101006: NewSkinID = new_Skin.AUG; break;

              case 101008: NewSkinID = new_Skin.M762; break;

              case 102001: NewSkinID = new_Skin.UZI; break;

              case 102002: NewSkinID = new_Skin.UMP; break;

              case 102003: NewSkinID = new_Skin.Vector; break;

              case 102004: NewSkinID = new_Skin.Thompson; break;

              case 102005: NewSkinID = new_Skin.Bizon; break;

              case 102105: NewSkinID = new_Skin.P90; break;

              case 103002: NewSkinID = new_Skin.M24; break;

              case 103003: NewSkinID = new_Skin.AWM; break;

              case 103004: NewSkinID = new_Skin.SKS; break;

              case 103006: NewSkinID = new_Skin.Mini14; break;

              case 103007: NewSkinID = new_Skin.MK14; break;

              case 103001: NewSkinID = new_Skin.K98; break;

              case 103012: NewSkinID = new_Skin.AMR; break;

              case 105002: NewSkinID = new_Skin.DP28; break;

              case 105001: NewSkinID = new_Skin.M249; break;

              case 105010: NewSkinID = new_Skin.MG3; break;

              case 108004: NewSkinID = new_Skin.Pan; break;

              case 101007: NewSkinID = new_Skin.QBZ; break;

              case 101100: NewSkinID = new_Skin.FAMAS; break;

              case 101102: NewSkinID = new_Skin.ACE32; break;

              default: break;

          }

          if (NewSkinID != -1) {

              for (int k = 0; k < AdditionalData.Num(); k++) {

                  if (!AdditionalData.IsValidIndex(k)) continue;

                  if (AdditionalData[k].EDataType == EBattleItemAdditionalDataType::EBattleItemAdditionalDataType__WeaponAvatar) {

                      AdditionalData[k].IntData = NewSkinID;

                      bFoundAvatar = true;

                      NeedRefreshBack = true;

                  }

              }

              if (!bFoundAvatar) {

                  FBattleItemAdditionalData NewEntry;

                  NewEntry.EDataType = EBattleItemAdditionalDataType::EBattleItemAdditionalDataType__WeaponAvatar;

                  NewEntry.IntData = NewSkinID;

                  // AdditionalData.Emplace(NewEntry); // Disabled due to TArray limitations

                  NeedRefreshBack = true;

              }

          }

      }

      if (NeedRefreshBack && Backpack) {

          Backpack->OnRep_ItemListNet();

      }

                            if (Config.AimEnable) {
                                  if (Tab2 == Tab2::AimMod1) {
                                    ASTExtraPlayerCharacter *Target = GetTargetForAimBot();
                            
                               if (Target) {
                        bool triggerOk = false;
                      if (Tab1 == Tab1::Aim1) {
                               triggerOk = localPlayer->bIsWeaponFiring;
                          } else  if (Tab1 == Tab1::Aim2) {
                                triggerOk = localPlayer->bIsGunADS;
                                } else   if (Tab1 == Tab1::Aim3) {
                                triggerOk = localPlayer->bIsWeaponFiring || localPlayer->bIsGunADS;
                  
                                } else triggerOk = true;
                     if (triggerOk) {
                             //  if (localPlayer->bIsWeaponFiring || localPlayer->bIsGunADS) {
                                        FVector targetAimPos = Target->GetBonePos("Head", {});
                
//if (Config.AimBot.Lessmmm) {
                                        
                                                    if (localPlayer->bIsGunADS) {
                                                        if (localPlayer->bIsWeaponFiring) {
                                                            float dist = localPlayer->GetDistanceTo(Target) / 100.f;                                                                                 
                                                            targetAimPos.Z -= dist * Config.RecoilSize;
                                                        }  
                                                    }
                                                    
                                                    
                                              
                                                            
                                            auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                                            if (WeaponManagerComponent) {
                                                auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                                                if ((int) propSlot.GetValue() >= 1 &&
                                                    (int) propSlot.GetValue() <= 3) {
                                                    auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                                                    if (CurrentWeaponReplicated) {
                                                        auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                                                        if (ShootWeaponComponent) {
                                                            UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
                                                            if (ShootWeaponEntityComponent) {
                                                                ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                                                                if (CurrentVehicle) {
                                                                    FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;
                                                                    float dist = localPlayer->GetDistanceTo(Target);
                                                                    auto timeToTravel = dist /
                                                                    ShootWeaponEntityComponent->BulletFireSpeed;
                                                                    targetAimPos = UMC->Add_VectorVector(targetAimPos,UMC->Multiply_VectorFloat(LinearVelocity, timeToTravel));
                                                                } else {
                                                                    FVector Velocity = Target->GetVelocity();
                                                                    float dist = localPlayer->GetDistanceTo(Target);
                                                                    auto timeToTravel = dist /
                                                                    ShootWeaponEntityComponent->BulletFireSpeed;
                                                                    targetAimPos = UMC->Add_VectorVector(targetAimPos, UMC->Multiply_VectorFloat(Velocity, timeToTravel));
                                                                }
                                                                
      
                                                            localPlayerController->ClientSetLocation(localPlayer->K2_GetActorLocation(), ToRotator(localPlayerController->PlayerCameraManager->CameraCache.POV.Location, targetAimPos));

         
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                
                }
                
                
        }

    }
    }
    g_LocalPlayer = localPlayer;
    g_LocalController = localPlayerController;
    //}
}}


void* (*oDeadBox)(UObject* pObj, UFunction* pFunc, void* pArgs);
void* hDeadBox(UObject* pObj, UFunction* pFunc, void* pArgs){
auto NRG = g_LocalPlayer;
auto NRG2 = g_LocalController;
/*
  //  UBulletHitInfoUploadComponent* Upload = (UBulletHitInfoUploadComponent*)g_LocalPlayer -> WeaponManagerComponent -> CurrentWeaponReplicated->CachedBulletHitInfoUploadComponent;
    if( std::string(pObj->GetName().c_str()).find("BulletHitInfoUploadComponent") != std::string::npos ) {
UBulletHitInfoUploadComponent *Upload = ( UBulletHitInfoUploadComponent *) pObj; 
    
    // Safety Check
    if (Upload)
    {
        // Setting parameters
        Upload->UploadInterval = 0.1f;
        Upload->bEnableTssSdkAntiData = false;
        Upload->bEnableTssSdkAntiDataFilter = false;
        Upload->bEnableTssSdkAntiDataFilterNew = false;
        Upload->bDisableDsTick = false; 
        Upload->bDisableDsAntiDataReport = false; 
        Upload->bEnableAddSPCShootData = false; 
        Upload->NeedSendSimpleCharacterHitData = false;  

        
        DebugLogUploadStatus(Upload);
        ToggleUploadSettings(Upload, true);

     //   if (ShouldUploadNow())
     //   {
            UploadBulletData(Upload);
     //   }
    }
}*/

     if (NRG2 == 0){
  //LOGO

 

if (std::string(pFunc -> GetFullName().c_str()).find("VehicleAvatarComponent_BP.VehicleAvatarComponent_BP_C.GetItemAvatarHandle") !=
      std::string::npos) {
 
        UVehicleAvatarComponent_GetItemAvatarHandle_Params * PARAMS = (UVehicleAvatarComponent_GetItemAvatarHandle_Params * ) pArgs;
        std::string SkinIDStr = std::to_string((int) PARAMS -> ItemId);
          if (Config.CarMod){
              
               if (strstr(SkinIDStr.c_str(), "1901")) {
            PARAMS -> ItemId = new_Skin.Moto;
          } else if (strstr(SkinIDStr.c_str(), "1903")) {
            PARAMS -> ItemId = new_Skin.Dacia;
          } else if (strstr(SkinIDStr.c_str(), "1911")) {
            PARAMS -> ItemId = new_Skin.Boat;
          } else if (strstr(SkinIDStr.c_str(), "1904")) {
            PARAMS -> ItemId = new_Skin.MiniBus;
          } else if (strstr(SkinIDStr.c_str(), "1914")) {
            PARAMS -> ItemId = new_Skin.Mirado;
          } else if (strstr(SkinIDStr.c_str(), "1915")) {
            PARAMS -> ItemId = new_Skin.Mirado;
          } else if (strstr(SkinIDStr.c_str(), "1907")) {
            PARAMS -> ItemId = new_Skin.Buggy;
          }else if (strstr(SkinIDStr.c_str(), "1961")) {
            PARAMS -> ItemId = new_Skin.CoupeRP;
          } else if (strstr(SkinIDStr.c_str(), "1953")) {
            PARAMS -> ItemId = new_Skin.Bigfoot;
          } else if (strstr(SkinIDStr.c_str(), "1908")) {
            PARAMS -> ItemId = new_Skin.UAZ;
          } 
              
    
          }
        return oDeadBox(pObj, pFunc, pArgs);
      
    }

 } else {

 }

     if (NRG2 == 0){
  //LOGO

   } else {
if( std::string(pObj->GetName().c_str()).find("DeadBoxAvatarComponent") != std::string::npos ) {
UDeadBoxAvatarComponent *DeadBoxPointer = ( UDeadBoxAvatarComponent *) pObj; 
if( std::string(pFunc->GetFullName().c_str()).find("GetLuaFilePath") != std::string::npos ) {
uint32_t Key = DeadBoxPointer->IsSelf();
if(NRG2->PlayerKey && NRG->WeaponManagerComponent->CurrentWeaponReplicated){
    if (Config.SkinEnable){ 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "AKM")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.AKM, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "Kar98K")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.K98, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "M24")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.M24, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "AWM")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.AWM, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "AMR")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.AMR, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "Mk14")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.MK14, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "ACE32")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.ACE32, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "Vector")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.Vector, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "UMP45")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.UMP, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "UZI")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.UZI, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "M16A4")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.M16A4, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "AUG")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.AUG, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "Groza")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.Groza, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "DP-28")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.DP28, true);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "M249")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.M249, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "MG3")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.MG3, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "SCAR-L")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.Scar, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "M762")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.M762, true);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
if(strstr(NRG->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponName().ToString(), "M416")){
DeadBoxPointer->ChangeItemAvatar(new_Skin.M416_1, true);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}}}}}
return oDeadBox(pObj, pFunc, pArgs);
}



 void *(*oProcessEvent)(UObject *pObj, UFunction *pFunc, void *pArgs);
void *hkProcessEvent(UObject *pObj, UFunction *pFunc, void *pArgs)
{

  if (pFunc)
    {
        if (pFunc->GetFullName() == "Function Engine.HUD.ReceiveDrawHUD")
        {
            AHUD *pHUD = (AHUD *)pObj;
            if (pHUD)
            {
                auto Params = (AHUD_ReceiveDrawHUD_Params *)pArgs;
                if (Params)
                {
                    RenderESP(pHUD);
                }
            }
        }
    }
    
       if (g_LocalController == 0){
  //LOGO

   } else {
    //ISLAND
      
 if (pFunc) {
 if (pFunc->GetFullName() == "Function ShadowTrackerExtra.STExtraPlayerController.BroadcastFatalDamageToClientWithStruct") {
 ASTExtraPlayerController *pController = (ASTExtraPlayerController *) pObj;
 if (pController) {
 auto Params = (ASTExtraPlayerController_BroadcastFatalDamageToClientWithStruct_Params *) pArgs;
if (Params) {
 auto GWorld = GetWorld();
 if (GWorld){
 if (GWorld->NetDriver->ServerConnection)
 if(GWorld->NetDriver->ServerConnection->PlayerController){
 ASTExtraPlayerController *localController = (ASTExtraPlayerController *)GWorld->NetDriver->ServerConnection->PlayerController;
 ASTExtraPlayerCharacter *localPlayer = (ASTExtraPlayerCharacter *)localController->AcknowledgedPawn;
 if(localController->PlayerKey == Params->FatalDamageParameter.CauserKey && !localController->STExtraBaseCharacter->CurrentVehicle && localPlayer->WeaponManagerComponent->CurrentWeaponReplicated){
int weapowep = localPlayer -> WeaponManagerComponent -> CurrentWeaponReplicated -> GetWeaponID();
//if (Config.OutfitEnable) {
if (SuitSkinHackHudSdk == 1) {
Params->FatalDamageParameter.CauserClothAvatarID = 1405870; //Blood Raven X-Suit (6-Star)
} else if (SuitSkinHackHudSdk == 2) {
Params->FatalDamageParameter.CauserClothAvatarID = 1405628; //Golden Pharaoh X-Suit (6-Star)
} else if (SuitSkinHackHudSdk == 3) {
Params->FatalDamageParameter.CauserClothAvatarID = 1406469; //Golden Pharaoh X-Suit (7-Star)
} else if (SuitSkinHackHudSdk == 4) {
Params->FatalDamageParameter.CauserClothAvatarID = 1406152; //Avalanche X-Suit (6-Star)
} else if (SuitSkinHackHudSdk == 5) {
Params->FatalDamageParameter.CauserClothAvatarID = 1406475; //Iridescence X-Suit (6-Star)
} else if (SuitSkinHackHudSdk == 6) {
Params->FatalDamageParameter.CauserClothAvatarID = 1405983; //Poseidon X-Suit (6-Star)
} else if (SuitSkinHackHudSdk == 7) {
Params->FatalDamageParameter.CauserClothAvatarID = 1406638; //Arcane Jester X-Suit (6-Star)
} else if (SuitSkinHackHudSdk == 8) {
Params->FatalDamageParameter.CauserClothAvatarID = 1406311;//Silvanus X-Suit (6-Star)
} else if (SuitSkinHackHudSdk == 9) {
Params->FatalDamageParameter.CauserClothAvatarID = 1406971; //Marmoris X-Suit (7-Star)
} else if (SuitSkinHackHudSdk == 10) { 
Params->FatalDamageParameter.CauserClothAvatarID = 1407103; //Fiore X-Suit
} else if (SuitSkinHackHudSdk == 11) { 
Params->FatalDamageParameter.CauserClothAvatarID = 1407259; //Ignis X-Suit (7-Star)
} else if (SuitSkinHackHudSdk == 12) { 
Params->FatalDamageParameter.CauserClothAvatarID = 1406872; // Stygian Liege X-Suit (6-Star) 
} else if (SuitSkinHackHudSdk == 13) { 
Params->FatalDamageParameter.CauserClothAvatarID = 1407366; //Galadria X-Suit (7-Star)
} 

//}

 if (Config.SkinEnable){ 
     if (weapowep == 101001 || weapowep == 1010011 || weapowep == 1010012 || weapowep == 1010013 || weapowep == 1010014 || weapowep == 1010015 || weapowep == 1010016 || weapowep == 1010017){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.AKM;
                     
                  
                 }
                           if (weapowep == 103001 || weapowep == 1030011 || weapowep == 1030012 || weapowep == 1030013 || weapowep == 1030014 || weapowep == 1030015 || weapowep == 1030016 || weapowep == 1030017){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.K98;
                     
                  
                 
                }
    if (weapowep == 103002 || weapowep == 1030021 || weapowep == 1030022 || weapowep == 1030023 || weapowep == 1030024 || weapowep == 1030025 || weapowep == 1030026 || weapowep == 1030027){
                
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.M24;
                     
                }
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         if (weapowep == 103003 || weapowep == 1030031 || weapowep == 1030032 || weapowep == 1030033 || weapowep == 1030034 || weapowep == 1030035 || weapowep == 1030036 || weapowep == 1030037){
                          
                
           
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.AWM;
                     
                  
                 
                }
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 103012 || weapowep == 1030121 || weapowep == 1030122 || weapowep == 1030123 || weapowep == 1030124 || weapowep == 1030125 || weapowep == 1030126 || weapowep == 1030127){
                       
            
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.AMR;
                     
                }
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
           
                         if (weapowep == 103007 || weapowep == 1030071 || weapowep == 1030072 || weapowep == 1030073 || weapowep == 1030074 || weapowep == 1030075 || weapowep == 1030076 || weapowep == 1030077){     
                  
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.MK14;
                     
                }
                
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
              
            
              
                                    if (weapowep == 101102 || weapowep == 1011021 || weapowep == 1011022 || weapowep == 1011023 || weapowep == 1011024 || weapowep == 1011025 || weapowep == 1011026 || weapowep == 1011027){        
               
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.ACE32;
                     
                  
                }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
              
                
                                    if (weapowep == 102003 || weapowep == 1020031 || weapowep == 1020032 || weapowep == 1020033 || weapowep == 1020034 || weapowep == 1020035 || weapowep == 1020036 || weapowep == 1020037){                      
                 
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.Vector;
                     
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                            if (weapowep == 102002 || weapowep == 1020021 || weapowep == 1020022 || weapowep == 1020023 || weapowep == 1020024 || weapowep == 1020025 || weapowep == 1020026 || weapowep == 1020027){                      

                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.UMP;
                     
                  
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                            if (weapowep == 102001 || weapowep == 1020011 || weapowep == 1020012 || weapowep == 1020013 || weapowep == 1020014 || weapowep == 1020015 || weapowep == 1020016 || weapowep == 1020017){        
              
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.UZI;
                     
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (weapowep == 101002 || weapowep == 1010021 || weapowep == 1010022 || weapowep == 1010023 || weapowep == 1010024 || weapowep == 10200155 || weapowep == 10200156 || weapowep == 1020015){        
               
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.M16A4;
                     
                 }
       
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
               if (weapowep == 101006 || weapowep == 1010061 || weapowep == 1010062 || weapowep == 1010063 || weapowep == 1010064 || weapowep == 1010065 || weapowep == 1010066 || weapowep == 1010067){                 
           
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.AUG;
                     
                }
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
               if (weapowep == 101005 || weapowep == 1010051 || weapowep == 1010052 || weapowep == 1010053 || weapowep == 1010054 || weapowep == 1010055 || weapowep == 1010056 || weapowep == 1010057){      
               
             
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.Groza;
                     
                }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
                     if (weapowep == 105002 || weapowep == 1050021 || weapowep == 1050022 || weapowep == 1050023 || weapowep == 1050025 || weapowep == 1050025 || weapowep == 1050026 || weapowep == 1050027){            
             
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.DP28;
                     
                }
                if (weapowep == 105001){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.M249;
                     
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
                
                               if (weapowep == 105010 || weapowep == 1050101 || weapowep == 1050102 || weapowep == 1050103 || weapowep == 1050104 || weapowep == 1050105 || weapowep == 1050106 || weapowep == 1050107){      
                
             
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.MG3;
                     
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
                
                            if (weapowep == 101003 || weapowep == 1010031 || weapowep == 1010032 || weapowep == 1010033 || weapowep == 1010034 || weapowep == 1010035 || weapowep == 1010036 || weapowep == 1010037){         
               
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.Scar;
                     
                 }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
                      if (weapowep == 101008 || weapowep == 1010081 || weapowep == 1010082 || weapowep == 1010083 || weapowep == 1010084 || weapowep == 1010085 || weapowep == 1010086 || weapowep == 1010087){      
             
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.M762;
                     
                 }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
                       if (weapowep == 101004 || weapowep == 1010041 || weapowep == 1010042 || weapowep == 1010043 || weapowep == 1010044 || weapowep == 1010045 || weapowep == 1010046 || weapowep == 1010047){      
    
               
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.M416_1;
                     
                 }
}}}}}}}}
}

    
    return oProcessEvent(pObj, pFunc, pArgs);
}


#define SLEEP_TIME 1000LL / 60LL
[[noreturn]] void *maps_thread(void *) {
while (true) {
auto t1 = std::chrono::steady_clock::now();
auto objs = UObject::GetGlobalObjects();

    for (int i = 0; i < objs.Num(); i++) {
        auto Object = objs.GetByIndex(i);
        if (isObjectInvalid(Object))
            continue;


            if (Object->IsA(UPlayerPetMovementComponent::StaticClass())) {
                auto Upload = (UPlayerPetMovementComponent *) Object;
           if (!strcmp(GetPackageName().c_str(), "com.tencent.ig")) {
            //  Upload->bEnableServerAntiCheat = false;
            }
       }   

        if (Object->IsA(UBulletHitInfoUploadComponent::StaticClass())) {
            auto Upload = (UBulletHitInfoUploadComponent *) Object;
            Upload->bEnableTssSdkAntiData = false;
            Upload->bEnableTssSdkAntiDataFilter = false;
            Upload->bEnableTssSdkAntiDataFilterNew = false;
            Upload->bDisableDsTick = true;
            Upload->bDisableDsAntiDataReport = true;
            Upload->bEnableAddSPCShootData = false;
            Upload->NeedSendSimpleCharacterHitData = false;
}

            if (Object->IsA(UMoveAntiCheatComponent::StaticClass())) {
                auto Upload = (UMoveAntiCheatComponent *) Object;
                
                Upload->MinMoveAntiCheatCheckIntervel2 = 1;
                Upload->MaxTotalMoveCheatTimes = 60;

            }

        }
    

std::vector<sRegion> tmp;
FILE *f = fopen("/proc/self/maps", "r");
if (f) {
char line[512];
while (fgets(line, sizeof line, f)) {
uintptr_t start, end;
char tmpProt[16];
if (sscanf(line, "%" PRIXPTR "-%" PRIXPTR " %16s %*s %*s %*s %*s", &start, &end, tmpProt) > 0) {
if (tmpProt[0] != 'r') {
tmp.push_back({start, end});
}
}
}
fclose(f);
}

trapRegions = std::move(tmp); // Move assignment
auto td = std::chrono::steady_clock::now() - t1;
std::chrono::milliseconds sleep_time = std::chrono::milliseconds(std::max(0LL, -std::chrono::duration_cast<std::chrono::milliseconds>(td).count()));
std::this_thread::sleep_for(sleep_time);
}
}
