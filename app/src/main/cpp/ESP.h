int DrawInt()
{
   // py = ScreenY/2;
   // px = ScreenX/2;
    return 0;
}
int xWidth =50;
int xtWidth =10;

int hpWidth = 50;
int hpHeight = 8;

int scWidth = 220;
int scHeight = 110;

int qtWidth = 220;
int qtHeight = 50;

int iconsize = 50;


void DrawESP(ImDrawList *draw) {
   int Wj_rs = 10;
   int Rj_rs = 15;
    



 if (!g_Token.empty() && !g_Auth.empty() && g_Token == g_Auth) {
     
     
        if (!strcmp(GetPackageName().c_str(), "com.bearmod")) {
         
       
            
            int playerCount = 0, robotCount = 0;

        draw->AddImage(Base64Image[1].textureId, ImVec2(glWidth / 2-115 - 50 / 2, 115), ImVec2(glWidth / 2-115 + 50 / 2, 115 + 50), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));
        draw->AddImage(Base64Image[2].textureId, ImVec2(glWidth / 2+115 - 50 / 2, 115), ImVec2(glWidth / 2+115 + 50 / 2, 115 + 50), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));
         if (playerCount == 0 && robotCount == 0) {
        draw->AddImage(Base64Image[3].textureId, ImVec2(glWidth / 2 - 50 / 2, 114), ImVec2(glWidth / 2 + 50 / 2, 114 + 50), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));
         }else{
         
        if(robotCount == 0){
            draw->AddTextX(ImVec2(glWidth / 2 + 36.5, 101.5 + 50 / 2 - 5), ImColor(0, 0, 0, 255),45, std::to_string(robotCount).c_str());
                draw->AddTextX(ImVec2(glWidth / 2 + 35, 100 + 50 / 2 - 5), ImColor(0, 255, 0), 45, std::to_string(robotCount).c_str());
           }else{
        draw->AddTextX(ImVec2(glWidth / 2 + 36.5, 101.5 + 50 / 2 - 5), ImColor(0, 0, 0, 255),45, std::to_string(robotCount).c_str());
                draw->AddTextX(ImVec2(glWidth / 2 + 35, 100 + 50 / 2 - 5), ImColor(255, 255, 0), 45, std::to_string(robotCount).c_str());
                draw->AddImage(Base64Image[4].textureId, ImVec2(glWidth / 2 - 50 / 2, 114), ImVec2(glWidth / 2 + 50 / 2, 114 + 50), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));
        }
         if(playerCount == 0){
             draw->AddTextX(ImVec2(glWidth / 2 - calcTextSize(std::to_string(playerCount).c_str(), 40) - 33.5, 101.5 + 50 / 2 - 5), ImColor(0, 0, 0, 255), 45, std::to_string(playerCount).c_str());
                draw->AddTextX(ImVec2(glWidth / 2 - calcTextSize(std::to_string(playerCount).c_str(), 40) - 35, 100 + 50 / 2 - 5), ImColor(0, 255, 0), 45, std::to_string(playerCount).c_str());
                  }else{
                      draw->AddTextX(ImVec2(glWidth / 2 - calcTextSize(std::to_string(playerCount).c_str(), 40) - 33.5, 101.5 + 50 / 2 - 5), ImColor(0, 0, 0, 255), 45, std::to_string(playerCount).c_str());
                draw->AddTextX(ImVec2(glWidth / 2 - calcTextSize(std::to_string(playerCount).c_str(), 40) - 35, 100 + 50 / 2 - 5), ImColor(255, 0, 0), 45, std::to_string(playerCount).c_str());
                draw->AddImage(Base64Image[5].textureId, ImVec2(glWidth / 2 - 50 / 2, 114), ImVec2(glWidth / 2 + 50 / 2, 114 + 50), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));
                      }
        }

            std::string str1;
            str1 += "Safe";
            auto Size1 = ImGui::CalcTextSize(str1.c_str(), 0, 36);

     }


          if (!Config.Handcam){

 if (!bScanPatternCompleted)
      return;
    
              auto GWorld = GetWorld();
    if (GWorld) {
        ULevel *PersistentLevel = GWorld->PersistentLevel;
        if (GWorld->PersistentLevel) {
           TArray<AActor *> Actors = *(TArray<AActor *> *)((uintptr_t)PersistentLevel + 0xA0);
//auto GWorld = GetWorld();
//  if (Canvas) {

    auto localPlayer = g_LocalPlayer;
       auto localPlayerController = g_LocalController;

  int totalEnemies = 0, totalBots = 0;
   if (localPlayerController == 0){
  //LOGO
Config.OutfitEnable = false;
   } else {
          
          }
if (localPlayerController && localPlayer)
{
    
auto *gGameplayStatics = (UGameplayStatics *)UGameplayStatics::StaticClass();

                    for (int i = 0; i < Actors.Num(); i++) {
                    if (isObjectPlayer(Actors[i])) {
                        auto Player = (ASTExtraPlayerCharacter *) Actors[i];
                        auto RootComponent = Player->RootComponent;
                        if (!RootComponent)
                            continue;

     if (localPlayer) {
                            if (Player->PlayerKey == localPlayer->PlayerKey)
                                continue;

                            if (Player->TeamID == localPlayer->TeamID)
                                continue;
                        }
             
if (Player->bDead)
    continue;
    
            
if (Player->bHidden)
    continue;
    
if (!Player->Mesh)
continue;

      if (Config.EspHideBot) {
                    if (Player->bEnsure)
                        continue;
				}
if (Player->bEnsure)
    totalBots++;
else
    totalEnemies++;
    
    
    int ColorEspAlert;
    int HPCOLOR;
                    if (Player->bEnsure) {
                   
                        ColorEspAlert = IM_COL32(154, 255, 60, 225);
                        HPCOLOR = IM_COL32(0, 255, 47, 255);
                    } else {
                        
                        ColorEspAlert = IM_COL32(171, 0, 169, 225);
                        HPCOLOR = IM_COL32(255, 30, 0, 255);
					}
    
  float Distance = Player->GetDistanceTo(localPlayer) / 100.f;
if (Distance < 1000.f) {
          if (Config.Alert) {
bool shit = false;
FVector MyPosition, EnemyPosition;
ASTExtraVehicleBase * CurrentVehiclea = Player->CurrentVehicle;
if (CurrentVehiclea) { 
MyPosition = CurrentVehiclea->RootComponent->RelativeLocation;
} else {
MyPosition = Player->RootComponent->RelativeLocation;}
ASTExtraVehicleBase * CurrentVehicle = localPlayer->CurrentVehicle;
if (CurrentVehicle) {
EnemyPosition = CurrentVehicle->RootComponent->RelativeLocation;
} else { 
EnemyPosition = localPlayer->RootComponent->RelativeLocation;
}FVector EntityPos = WorldToRadar(localPlayerController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw, MyPosition, EnemyPosition, NULL, NULL, Vector3(glWidth, glHeight, 0), shit); 
FVector angle = FVector();
Vector3 forward = Vector3((float)(glWidth / 2) - EntityPos.X, (float)(glHeight / 2) - EntityPos.Y, 0.0f);  
VectorAnglesRadar(forward, angle);
const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f);
const auto new_point_x = (glWidth / 2) + (75) / 2 * 8 * cosf(angle_yaw_rad);  
const auto new_point_y = (glHeight / 2) + (75) / 2 * 8 * sinf(angle_yaw_rad);  
std::array<Vector3, 3> points { Vector3(new_point_x - ((45) / 4 + 3.5f) / 2, new_point_y - ((55) / 4 + 3.5f) / 2, 0.f), Vector3(new_point_x + ((45) / 4 + 3.5f) / 4, new_point_y, 0.f), Vector3(new_point_x - ((45) / 4 + 3.5f) / 2, new_point_y + ((55) / 4 + 3.5f) / 2, 0.f)};
RotateTriangle(points, angle.Y + 180.f);  
          auto AboveHead = Player->GetHeadLocation(true);
                                    
                                    FVector2D AboveHeadSc;
          if (SDK::UGameplayStatics::ProjectWorldToScreen(localPlayerController, AboveHead, false,  &AboveHeadSc)) {
                                    
                             // 
                             
                            }else{
                                
draw->AddTriangleFilled(ImVec2(points.at(0).X, points.at(0).Y), ImVec2(points.at(1).X, points.at(1).Y), ImVec2(points.at(2).X, points.at(2).Y), ColorEspAlert);
draw->AddTriangle(ImVec2(points.at(0).X, points.at(0).Y), ImVec2(points.at(1).X, points.at(1).Y), ImVec2(points.at(2).X, points.at(2).Y), IM_COL32(0, 0, 0, 255), 18.18f);
draw->AddTriangle(ImVec2(points.at(0).X, points.at(0).Y), ImVec2(points.at(1).X, points.at(1).Y), ImVec2(points.at(2).X, points.at(2).Y), ColorEspAlert, 15.18f);
}
}

                        
                        
if (Config.RadarMap) {
                            bool out = false;
                            static struct Vector3 Pos;
                            static struct Vector3 Size;
                            static ImVec2 radarPosition(Pos.X, Pos.Y);
                            Pos.X = glWidth / 5.5;
                            Pos.Y = glHeight / 4.1;
                            Size.X = 170;
                            Size.Y = 170;
                            float RadarCenterX = Pos.X + (Size.X / 2);
                            float RadarCenterY = Pos.Y + (Size.Y / 2);
                            ImColor LineColor = ImColor(255, 255, 255, 255);
                            ImColor PointColor = ImColor(255, 0, 0, 255);
                            float TransparentBoxSize = 160.0f;
                            ImColor BackgroundColor = ImColor(0, 0, 0, 75);
                            ImColor TransparentBoxColor = BackgroundColor;
                           draw->AddRectFilled(ImVec2(Pos.X - (TransparentBoxSize - Size.X) / 2, Pos.Y - (TransparentBoxSize - Size.Y) / 2), ImVec2(Pos.X + Size.X + (TransparentBoxSize - Size.X) / 2, Pos.Y + Size.Y + (TransparentBoxSize - Size.Y) / 2), TransparentBoxColor, 0.0f, 0);
                            draw->AddLine(ImVec2(Pos.X, Pos.Y), ImVec2(Pos.X + Size.X, Pos.Y), LineColor, 1.0f);
                            draw->AddLine(ImVec2(Pos.X, Pos.Y + Size.Y), ImVec2(Pos.X + Size.X, Pos.Y + Size.Y), LineColor, 1.0f);
                            draw->AddLine(ImVec2(Pos.X, Pos.Y), ImVec2(Pos.X, Pos.Y + Size.Y), LineColor, 1.0f);
                            draw->AddLine(ImVec2(Pos.X + Size.X, Pos.Y), ImVec2(Pos.X + Size.X, Pos.Y + Size.Y), LineColor, 1.0f);
                            draw->AddLine(ImVec2(RadarCenterX, Pos.Y), ImVec2(RadarCenterX, Pos.Y + Size.Y), LineColor, 1.0f);
                            draw->AddLine(ImVec2(Pos.X, RadarCenterY), ImVec2(Pos.X + Size.X, RadarCenterY), LineColor, 1.0f);
                            draw->AddCircleFilled(ImVec2(RadarCenterX, RadarCenterY), 3.0f, LineColor, 1000);
                            
                            FVector MyPosition = Player->RootComponent->RelativeLocation;
                            FVector EnemyPosition = localPlayer->RootComponent->RelativeLocation;
                            FVector single = WorldToRadar(localPlayerController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw, MyPosition, EnemyPosition, Pos.X, Pos.Y, Size, out);
                            if (Distance >= 0.0f && Distance < 500.0f) {
                            draw->AddCircleFilled(ImVec2(single.X, single.Y), 3, ColorEspAlert);
                            }
                            }//end radar

                        
                        
                        long BoneColor = IM_COL32(255, 0, 0, 255);
                     
                            
                            if (!localPlayerController->LineOfSightTo(Player, {0, 0, 0}, true)) {
                                BoneColor = IM_COL32(0, 255, 0, 255);
                                
                            }
                        
                   long linecolor = IM_COL32(0, 255, 0, 255);
                             
                       if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager, GetBoneLocation(Player, "Head"), true))
                                {
                    linecolor = IM_COL32(255, 255, 255, 255);
                             
                            }

                        auto Head = Player->GetBonePos("Head", {});
                        auto Root = Player->GetBonePos("Root", {});
                        
                        auto uparmr = Player->GetBonePos("upperarm_r", {});
                        auto uparml = Player->GetBonePos("upperarm_l", {});
                        
                        auto lowarmr = Player->GetBonePos("lowerarm_r", {});
                        auto lowarml = Player->GetBonePos("lowerarm_l", {});
                        
                        auto handr = Player->GetBonePos("hand_r", {});
                        auto handl = Player->GetBonePos("hand_l", {});
                        
                        auto itemr = Player->GetBonePos("item_r", {});
                        auto iteml = Player->GetBonePos("item_l", {});
                        
                        auto clavicler = Player->GetBonePos("clavicle_r", {});
                        auto claviclel = Player->GetBonePos("clavicle_l", {});
                        
                        auto neck = Player->GetBonePos("neck_01", {});
                        auto spain01 = Player->GetBonePos("spine_01", {});
                        
                        auto spain02 = Player->GetBonePos("spine_02", {});
                        auto spain03 = Player->GetBonePos("spine_03", {});
                        
                        auto pelvis = Player->GetBonePos("pelvis", {});
                        auto calfl = Player->GetBonePos("calf_l", {});
                        
                        auto calfr = Player->GetBonePos("calf_r", {});
                        auto thighl = Player->GetBonePos("thigh_l", {});
                        
                        auto thighr = Player->GetBonePos("thigh_r", {});
                        auto footr = Player->GetBonePos("foot_r", {});
                        
                        auto footl = Player->GetBonePos("foot_l", {});

                        
                        auto PlayerCameraManager = localPlayerController->PlayerCameraManager;
                    CameraCache =PlayerCameraManager->CameraCache;
                            FVector HeadNrg = GetBoneLocationByName(Player, "Head");
                            FVector2D HeadNrgSc;
                    HeadNrgSc =  WorldToScreen360(HeadNrg, CameraCache.POV);
             
                            
                       if (Config.EspLine) {
                       
                               
                                auto mWidthScaleGun = std::min(0.006f * Distance, 100.f);
                                    auto mWidthGun = 20.f - mWidthScaleGun;
                                    auto mHeightGun = mWidthGun * 0.125f;
                                 //   GunHeadSc.X -= (mWidthGun / 2 - 20);
                                    HeadNrgSc.Y -= (mHeightGun * 1.4f + 15);
                                                
                               draw->AddLine({(float) glWidth / 2, 140}, {HeadNrgSc.X, HeadNrgSc.Y - 21} , linecolor, 1.7f);
                        }
                        
                        
                        ImVec2 HeadSc, uparmrSC, uparmlSC, lowarmrSC, lowarmlSC, handrSC, handlSC, itemrSC, itemlSC, upperarmtwist01rSC, upperarmtwist01lSC, claviclerSC, claviclelSC, neckSC, spain01SC, spain02SC, spain03SC, pelvisSC;
                        ImVec2 RootSc, calflSC,calfrSC,thighlSC,thighrSC,calftwist01lSC,calftwist01rSC,thightwist01lSC,thightwist01rSC,footrSC,footlSC,lowerarmtwist01lSC,lowerarmtwist01rSC;
                        
                        
                           if(WorldToScreenBone(Head, (FVector2D *)& HeadSc) && 
                           WorldToScreenBone(Root, (FVector2D *)& RootSc) &&
                           WorldToScreenBone(uparmr,  (FVector2D *)& uparmrSC) &&
                           WorldToScreenBone(uparml,  (FVector2D *)& uparmlSC) &&
                           WorldToScreenBone(lowarml, (FVector2D *)& lowarmlSC) &&
                           WorldToScreenBone(lowarmr, (FVector2D *)& lowarmrSC) &&
                           WorldToScreenBone(handr,  (FVector2D *)& handrSC) &&
                           WorldToScreenBone(handl,  (FVector2D *)& handlSC) &&
                           WorldToScreenBone(itemr, (FVector2D *)& itemrSC) &&
                           WorldToScreenBone(iteml,  (FVector2D *)& itemlSC) &&
                           WorldToScreenBone(clavicler, (FVector2D *) & claviclerSC) &&
                           WorldToScreenBone(claviclel, (FVector2D *) & claviclelSC) &&
                           WorldToScreenBone(neck, (FVector2D *) & neckSC) &&
                           WorldToScreenBone(spain01, (FVector2D *) & spain01SC) &&
                           WorldToScreenBone(spain02,  (FVector2D *)& spain02SC) &&
                           WorldToScreenBone(spain03, (FVector2D *)& spain03SC) &&
                           WorldToScreenBone(pelvis,  (FVector2D *)& pelvisSC) &&
                           WorldToScreenBone(calfl,  (FVector2D *)& calflSC) &&
                           WorldToScreenBone(calfr,  (FVector2D *)& calfrSC) &&
                           WorldToScreenBone(thighl, (FVector2D *) & thighlSC) &&
                           WorldToScreenBone(thighr,  (FVector2D *)& thighrSC) &&
                           WorldToScreenBone(footr,  (FVector2D *)& footrSC) &&
                           WorldToScreenBone(footl, (FVector2D *) & footlSC)) {

                              if (Config.Box) {
                            float boxHeight = abs(HeadSc.y - RootSc.y);
                                    float boxWidth = boxHeight * 0.65f;
                                    ImVec2 vStart = {HeadSc.x - (boxWidth / 2), HeadSc.y};
                                    ImVec2 vEnd = {vStart.x + boxWidth, vStart.y + boxHeight};

                                    draw->AddRect(vStart, vEnd, IM_COL32(255, 255, 255, 255), 1.5f, 240, 1.7f);

                                    
                                             }

                        
                        
                              if (Config.EspBone) {
                                                             
                   
                       if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,neck, true))
                                {
                                draw->AddLine({HeadSc.x, HeadSc.y}, {neckSC.x, neckSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({HeadSc.x, HeadSc.y}, {neckSC.x, neckSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,clavicler, true))
                                {
                                draw->AddLine({neckSC.x, neckSC.y}, {claviclerSC.x, claviclerSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({neckSC.x, neckSC.y}, {claviclerSC.x, claviclerSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,uparmr, true))
                                {
                                draw->AddLine({claviclerSC.x, claviclerSC.y}, {uparmrSC.x, uparmrSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({claviclerSC.x, claviclerSC.y}, {uparmrSC.x, uparmrSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,lowarmr, true))
                                {
                                draw->AddLine({uparmrSC.x, uparmrSC.y}, {lowarmrSC.x, lowarmrSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({uparmrSC.x, uparmrSC.y}, {lowarmrSC.x, lowarmrSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,handr, true))
                                {
                                draw->AddLine({lowarmrSC.x, lowarmrSC.y}, {handrSC.x, handrSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({lowarmrSC.x, lowarmrSC.y}, {handrSC.x, handrSC.y}, IM_COL32(0, 255, 0, 255), 
                                1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,itemr, true))
                                {
                                draw->AddLine({handrSC.x, handrSC.y}, {itemrSC.x, itemrSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({handrSC.x, handrSC.y}, {itemrSC.x, itemrSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }                                                                                               
                                                                
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,claviclel, true))
                                {
                                draw->AddLine({neckSC.x, neckSC.y}, {claviclelSC.x, claviclelSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({neckSC.x, neckSC.y}, {claviclelSC.x, claviclelSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,uparml, true))
                                {
                                draw->AddLine({claviclelSC.x, claviclelSC.y}, {uparmlSC.x, uparmlSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({claviclelSC.x, claviclelSC.y}, {uparmlSC.x, uparmlSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,lowarml, true))
                                {
                                draw->AddLine({uparmlSC.x, uparmlSC.y}, {lowarmlSC.x, lowarmlSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({uparmlSC.x, uparmlSC.y}, {lowarmlSC.x, lowarmlSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,handl, true))
                                {
                                draw->AddLine({lowarmlSC.x, lowarmlSC.y}, {handlSC.x, handlSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({lowarmlSC.x, lowarmlSC.y}, {handlSC.x, handlSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,iteml, true))
                                {
                                draw->AddLine({handlSC.x, handlSC.y}, {itemlSC.x, itemlSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({handlSC.x, handlSC.y}, {itemlSC.x, itemlSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,spain03, true))
                                {
                                draw->AddLine({neckSC.x, neckSC.y}, {spain03SC.x, spain03SC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({neckSC.x, neckSC.y}, {spain03SC.x, spain03SC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,spain02, true))
                                {
                                draw->AddLine({spain03SC.x, spain03SC.y}, {spain02SC.x, spain02SC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({spain03SC.x, spain03SC.y}, {spain02SC.x, spain02SC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,spain01, true))
                                {
                                draw->AddLine({spain02SC.x, spain02SC.y}, {spain01SC.x, spain01SC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({spain02SC.x, spain02SC.y}, {spain01SC.x, spain01SC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,pelvis, true))
                                {
                                draw->AddLine({spain01SC.x, spain01SC.y}, {pelvisSC.x, pelvisSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({spain01SC.x, spain01SC.y}, {pelvisSC.x, pelvisSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,thighr, true))
                                {
                                draw->AddLine({pelvisSC.x, pelvisSC.y}, {thighrSC.x, thighrSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({pelvisSC.x, pelvisSC.y}, {thighrSC.x, thighrSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,calfr, true))
                                {
                                draw->AddLine({thighrSC.x, thighrSC.y}, {calfrSC.x, calfrSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({thighrSC.x, thighrSC.y}, {calfrSC.x, calfrSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,footr, true))
                                {
                                draw->AddLine({calfrSC.x, calfrSC.y}, {footrSC.x, footrSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({calfrSC.x, calfrSC.y}, {footrSC.x, footrSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,thighl, true))
                                {
                                draw->AddLine({pelvisSC.x, pelvisSC.y}, {thighlSC.x, thighlSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({pelvisSC.x, pelvisSC.y}, {thighlSC.x, thighlSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,calfl, true))
                                {
                                draw->AddLine({thighlSC.x, thighlSC.y}, {calflSC.x, calflSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({thighlSC.x, thighlSC.y}, {calflSC.x, calflSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,footl, true))
                                {
                                draw->AddLine({calflSC.x, calflSC.y}, {footlSC.x, footlSC.y}, IM_COL32(255, 0, 0, 255),
 1.6f);
                                }else{
                                draw->AddLine({calflSC.x, calflSC.y}, {footlSC.x, footlSC.y}, IM_COL32(0, 255, 0, 255),
 1.6f);
                                }
                               
                            }

                            
                               if(Config.Health){

                                int CurHP = (int) std::max(0, std::min((int) Player->Health, (int) Player->HealthMax));
                                int MaxHP = (int) Player->HealthMax;

                                long HPColor;
                                long HPBordersColor;
                                
                                if (Player->bEnsure) {//

                                HPColor = IM_COL32(0, 200, 0, 90);
                              //  HPBordersColor = IM_COL32(0, 200, 0, 120);
                                HPBordersColor = IM_COL32(200, 0, 0, 120);
                                
                                } else {
                                
                                HPColor = IM_COL32(200, 0, 0, 90);
                                HPBordersColor = IM_COL32(200, 0, 0, 120);
                                
                                }//
auto mWidthScale = std::min(0.0f * 24.0f, 0.0f); //100  75 50 | 24
                            
                                    auto mWidth = 100.0f - mWidthScale;
                                     if (Player->Health == 0.0f && !Player->bDead) {   
                                     
                                     CurHP = Player->NearDeathBreath;
                                    if (Player->NearDeatchComponent) {
                                        MaxHP = Player->NearDeatchComponent->BreathMax;
                                    }
                                     HPBordersColor = IM_COL32(255, 255, 255, 120);
                                     HPColor = IM_COL32(255, 255, 255, 90);

                                }//
                                
                                

                                draw->PathLineTo(ImVec2(HeadSc.x - 50, HeadSc.y - 10));
                                draw->PathLineTo(ImVec2(HeadSc.x - 50 + CurHP * 100 / MaxHP, HeadSc.y - 10));
                                draw->PathLineTo(ImVec2(HeadSc.x - 50 + CurHP * 100 / MaxHP + 9, HeadSc.y - 20));
                                draw->PathLineTo(ImVec2(HeadSc.x - 50 + CurHP * 100 / MaxHP, HeadSc.y - 30));
                                draw->PathLineTo(ImVec2(HeadSc.x - 50, HeadSc.y - 30));
                                draw->PathLineTo(ImVec2(HeadSc.x - 50 - 9, HeadSc.y - 20));                                
                                draw->PathFillConvex(HPColor);//
 
                                draw->PathLineTo(ImVec2(HeadSc.x - 50, HeadSc.y - 10));
                                draw->PathLineTo(ImVec2(HeadSc.x - 50 + 100, HeadSc.y - 10));
                                draw->PathLineTo(ImVec2(HeadSc.x - 50 + 100 + 9, HeadSc.y - 20));//
                                draw->PathLineTo(ImVec2(HeadSc.x - 50 + 100, HeadSc.y - 30));
                                draw->PathLineTo(ImVec2(HeadSc.x - 50, HeadSc.y - 30));
                                draw->PathLineTo(ImVec2(HeadSc.x - 50 - 9, HeadSc.y - 20));
                                draw->PathStroke(HPBordersColor, 5);//
                                
                         } //
                         
                               if (Config.Name){
                                    float boxWidth = 464 / 1.6f;
                                                boxWidth -= std::min(
                                                        ((boxWidth / 2) / 00.0f) * Distance,
                                                        boxWidth / 2);
                                                float boxHeight = boxWidth * 0.15f;


                                                std::string s;
                                                
                                                if (Player->bEnsure) {
                                                    s += "      BOT";
                                                } else {
                                                       s += Player->PlayerName.ToString();
                                                 //   s = Player->PlayerName.ToWString();
                                                }

                                               draw->AddText(Chinese, 23.0f, {HeadSc.x- (boxWidth / 3.3f),HeadSc.y- (boxHeight * 1.48f)},IM_COL32(255, 255, 255, 255), s.c_str());
                                                
                            }
                            
                             
                            
                                if (Config.TeamId) {
            std::string s;
    
            
            
        s += "Team: ";                        
         s += std::to_string(Player->TeamID);
        s += "";                        
      Fly_Draw->DrawStrokeText(HeadSc.x - 45, HeadSc.y - 58, ImColor(255,200,0,255), s.c_str());

    }                               
                            

                         
                            
std::unordered_map<int, TextureInfo> weaponTextures = {
    // Assault Rifles
    {101001, ID101001}, {1010011, ID101001}, {1010012, ID101001}, {1010013, ID101001}, {1010014, ID101001}, {1010015, ID101001}, {1010016, ID101001}, {1010017, ID101001},
    {101002, ID101002}, {1010021, ID101002}, {1010022, ID101002}, {1010023, ID101002}, {1010024, ID101002}, {1010025, ID101002}, {1010026, ID101002}, {1010027, ID101002},
    {101003, ID101003}, {1010031, ID101003}, {1010032, ID101003}, {1010033, ID101003}, {1010034, ID101003}, {1010035, ID101003}, {1010036, ID101003}, {1010037, ID101003},
    {101004, ID101004}, {1010041, ID101004}, {1010042, ID101004}, {1010043, ID101004}, {1010044, ID101004}, {1010045, ID101004}, {1010046, ID101004}, {1010047, ID101004},
    {101005, ID101005}, {1010051, ID101005}, {1010052, ID101005}, {1010053, ID101005}, {1010054, ID101005}, {1010055, ID101005}, {1010056, ID101005}, {1010057, ID101005},
    {101006, ID101006}, {1010061, ID101006}, {1010062, ID101006}, {1010063, ID101006}, {1010064, ID101006}, {1010065, ID101006}, {1010066, ID101006}, {1010067, ID101006},
    {101007, ID101007}, {1010071, ID101007}, {1010072, ID101007}, {1010073, ID101007}, {1010074, ID101007}, {1010075, ID101007}, {1010076, ID101007}, {1010077, ID101007},
    {101008, ID101008}, {1010081, ID101008}, {1010082, ID101008}, {1010083, ID101008}, {1010084, ID101008}, {1010085, ID101008}, {1010086, ID101008}, {1010087, ID101008},
    {101009, ID101009}, {1010091, ID101009}, {1010092, ID101009}, {1010093, ID101009}, {1010094, ID101009}, {1010095, ID101009}, {1010096, ID101009}, {1010097, ID101009},
    {101010, ID101010}, {1010101, ID101010}, {1010102, ID101010}, {1010103, ID101010}, {1010104, ID101010}, {1010105, ID101010}, {1010106, ID101010}, {1010107, ID101010},
    {101100, NFAMAS}, {1011001, NFAMAS}, {1011002, NFAMAS}, {1011003, NFAMAS}, {1011004, NFAMAS}, {1011005, NFAMAS}, {1011006, NFAMAS}, {1011007, NFAMAS},
    {101102, NACE32}, {1011021, NACE32}, {1011022, NACE32}, {1011023, NACE32}, {1011024, NACE32}, {1011025, NACE32}, {1011026, NACE32}, {1011027, NACE32},
    // SMGs
    {102001, ID102001}, {1020011, ID102001}, {1020012, ID102001}, {1020013, ID102001}, {1020014, ID102001}, {1020015, ID102001},
    {102002, ID102002}, {1020021, ID102002}, {1020022, ID102002}, {1020023, ID102002}, {1020024, ID102002}, {1020025, ID102002},
    {102003, ID102003}, {1020031, ID102003}, {1020032, ID102003}, {1020033, ID102003}, {1020034, ID102003}, {1020035, ID102003}, {1020036, ID102003}, {1020037, ID102003},
    {102004, ID102004}, {1020041, ID102004}, {1020042, ID102004}, {1020043, ID102004}, {1020044, ID102004}, {1020045, ID102004}, {1020046, ID102004}, {1020047, ID102004},
    {102005, ID102005}, {1020051, ID102005}, {1020052, ID102005}, {1020053, ID102005}, {1020054, ID102005}, {1020055, ID102005}, {1020056, ID102005}, {1020057, ID102005},
    {102007, ID102007}, {1020071, ID102007}, {1020072, ID102007}, {1020073, ID102007}, {1020074, ID102007}, {1020075, ID102007}, {1020076, ID102007}, {1020077, ID102007},
    {102105, ID102105}, {1021051, ID102105}, {1021052, ID102105}, {1021053, ID102105}, {1021054, ID102105}, {1021055, ID102105}, {1021056, ID102105}, {1021057, ID102105},
    // Snipers
    {103001, hand.KAR98K}, {1030011, hand.KAR98K}, {1030012, hand.KAR98K}, {1030013, hand.KAR98K}, {1030014, hand.KAR98K}, {1030015, hand.KAR98K}, {1030016, hand.KAR98K}, {1030017, hand.KAR98K},
    {103002, ID103002}, {1030021, ID103002}, {1030022, ID103002}, {1030023, ID103002}, {1030024, ID103002}, {1030025, ID103002}, {1030026, ID103002}, {1030027, ID103002},
    {103003, ID103003}, {1030031, ID103003}, {1030032, ID103003}, {1030033, ID103003}, {1030034, ID103003}, {1030035, ID103003}, {1030036, ID103003}, {1030037, ID103003},
    {103004, ID103004}, {1030041, ID103004}, {1030042, ID103004}, {1030043, ID103004}, {1030044, ID103004}, {1030045, ID103004}, {1030046, ID103004}, {1030047, ID103004},
    {103005, ID103005}, {1030051, ID103005}, {1030052, ID103005}, {1030053, ID103005}, {1030054, ID103005}, {1030055, ID103005}, {1030056, ID103005}, {1030057, ID103005},
    {103006, ID103006}, {1030061, ID103006}, {1030062, ID103006}, {1030063, ID103006}, {1030064, ID103006}, {1030065, ID103006}, {1030066, ID103006}, {1030067, ID103006},
    {103007, ID103007}, {1030071, ID103007}, {1030072, ID103007}, {1030073, ID103007}, {1030074, ID103007}, {1030075, ID103007}, {1030076, ID103007}, {1030077, ID103007},
    {103008, ID103008}, {1030081, ID103008}, {1030082, ID103008}, {1030083, ID103008}, {1030084, ID103008}, {1030085, ID103008}, {1030086, ID103008}, {1030087, ID103008},
    {103009, hand.SLR}, {1030091, hand.SLR}, {1030092, hand.SLR}, {1030093, hand.SLR}, {1030094, hand.SLR}, {1030095, hand.SLR}, {1030096, hand.SLR}, {1030097, hand.SLR},
    {103010, ID103010}, {1030101, ID103010}, {1030102, ID103010}, {1030103, ID103010}, {1030104, ID103010}, {1030105, ID103010}, {1030106, ID103010}, {1030107, ID103010},
    {103011, ID103011}, {1030111, ID103011}, {1030112, ID103011}, {1030113, ID103011}, {1030114, ID103011}, {1030115, ID103011}, {1030116, ID103011}, {1030117, ID103011},
    {103012, ID103012}, {1030121, ID103012}, {1030122, ID103012}, {1030123, ID103012}, {1030124, ID103012}, {1030125, ID103012}, {1030126, ID103012}, {1030127, ID103012},
    {103100, NMk12}, {1031001, NMk12}, {1031002, NMk12}, {1031003, NMk12}, {1031004, NMk12}, {1031005, NMk12}, {1031006, NMk12}, {1031007, NMk12},
    // Shotguns
    {104001, ID104001}, {1040011, ID104001}, {1040012, ID104001}, {1040013, ID104001}, {1040014, ID104001}, {1040015, ID104001}, {1040016, ID104001}, {1040017, ID104001},
    {104002, ID104002}, {1040021, ID104002}, {1040022, ID104002}, {1040023, ID104002}, {1040024, ID104002}, {1040025, ID104002}, {1040026, ID104002}, {1040027, ID104002},
    {104003, ID104003}, {1040031, ID104003}, {1040032, ID104003}, {1040033, ID104003}, {1040034, ID104003}, {1040035, ID104003}, {1040036, ID104003}, {1040037, ID104003},
    {104004, ID104004}, {1040041, ID104004}, {1040042, ID104004}, {1040043, ID104004}, {1040044, ID104004}, {1040045, ID104004}, {1040046, ID104004}, {1040047, ID104004},
    // LMGs
    {105001, ID105001}, {1050011, ID105001}, {1050012, ID105001}, {1050013, ID105001}, {1050014, ID105001}, {1050015, ID105001}, {1050016, ID105001}, {1050017, ID105001},
    {105002, ID105002}, {1050021, ID105002}, {1050022, ID105002}, {1050023, ID105002}, {1050024, ID105002}, {1050025, ID105002}, {1050026, ID105002}, {1050027, ID105002},
    // Pistols
    {106001, hand.P92}, {1060011, hand.P92}, {1060012, hand.P92}, {1060013, hand.P92}, {1060014, hand.P92}, {1060015, hand.P92}, {1060016, hand.P92}, {1060017, hand.P92},
    {106002, hand.P1911}, {1060021, hand.P1911}, {1060022, hand.P1911}, {1060023, hand.P1911}, {1060024, hand.P1911}, {1060025, hand.P1911}, {1060026, hand.P1911}, {1060027, hand.P1911},
    {106003, hand.R1895}, {1060031, hand.R1895}, {1060032, hand.R1895}, {1060033, hand.R1895}, {1060034, hand.R1895}, {1060035, hand.R1895}, {1060036, hand.R1895}, {1060037, hand.R1895},
    {106004, hand.P18C}, {1060041, hand.P18C}, {1060042, hand.P18C}, {1060043, hand.P18C}, {1060044, hand.P18C}, {1060045, hand.P18C}, {1060046, hand.P18C}, {1060047, hand.P18C},
    {106005, hand.R45}, {1060051, hand.R45}, {1060052, hand.R45}, {1060053, hand.R45}, {1060054, hand.R45}, {1060055, hand.R45}, {1060056, hand.R45}, {1060057, hand.R45},
    {106006, hand.Sawed_off}, {1060061, hand.Sawed_off}, {1060062, hand.Sawed_off}, {1060063, hand.Sawed_off}, {1060064, hand.Sawed_off}, {1060065, hand.Sawed_off}, {1060066, hand.Sawed_off}, {1060067, hand.Sawed_off},
    {106008, NVz61}, {1060081, NVz61}, {1060082, NVz61}, {1060083, NVz61}, {1060084, NVz61}, {1060085, NVz61}, {1060086, NVz61}, {1060087, NVz61},
    {106010, NDesertEagle}, {1060101, NDesertEagle}, {1060102, NDesertEagle}, {1060103, NDesertEagle}, {1060104, NDesertEagle}, {1060105, NDesertEagle}, {1060106, NDesertEagle}, {1060107, NDesertEagle},
    // Crossbow
    {107001, ID107001}, {1070011, ID107001}, {1070012, ID107001}, {1070013, ID107001}, {1070014, ID107001}, {1070015, ID107001}, {1070016, ID107001}, {1070017, ID107001},
    // Melee
    {108001, ID大砍刀}, {1080011, ID大砍刀}, {1080012, ID大砍刀}, {1080013, ID大砍刀}, {1080014, ID大砍刀}, {1080015, ID大砍刀}, {1080016, ID大砍刀}, {1080017, ID大砍刀},
    {108002, ID撬棍}, {1080021, ID撬棍}, {1080022, ID撬棍}, {1080023, ID撬棍}, {1080024, ID撬棍}, {1080025, ID撬棍}, {1080026, ID撬棍}, {1080027, ID撬棍},
    {108003, ID镰刀}, {1080031, ID镰刀}, {1080032, ID镰刀}, {1080033, ID镰刀}, {1080034, ID镰刀}, {1080035, ID镰刀}, {1080036, ID镰刀}, {1080037, ID镰刀},
    {108004, hand.PAN}, {1080041, hand.PAN}, {1080042, hand.PAN}, {1080043, hand.PAN}, {1080044, hand.PAN}, {1080045, hand.PAN}, {1080046, hand.PAN}, {1080047, hand.PAN},
    // Grenades
    {602001, ID震撼弹},
    {602002, ID烟雾弹},
    {602003, ID燃烧瓶},
    {602004, ID手雷弹},
    // Special
    {108005, WeaponImage[44]},
};

auto DrawWeaponIcon = [&](ImDrawList* draw, TextureInfo texture, FVector Head) {
    if (!texture.textureId) return;
    FVector2D ImageHeadSc;
    if (!WorldToScreenBone(Head, &ImageHeadSc)) return;
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);
    draw->AddImage(texture.textureId, {ImageHeadSc.X + 50, rect.y - 41}, {ImageHeadSc.X - 70, rect.y - 0});
};
   if(Config.Weapon) {
       
                auto WeaponManagerComponent = Player->WeaponManagerComponent;                              
                if (WeaponManagerComponent) {
                auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
                if (CurrentWeaponReplicated) {
                int wppp = CurrentWeaponReplicated->GetWeaponID();
               std::string weaponName = CurrentWeaponReplicated->GetWeaponName().ToString();

                 
    if (wppp <=0 || wppp >=10008611)
    {
    TextureInfo textureInfo{};
textureInfo = ID拳头;
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70
//draw->AddImage(textureInfo.textureId, ImVec2(HeadSc.x+160 - scWidth+1, HeadSc.y+32 - iconsize -5 - scHeight+1), ImVec2(HeadSc.x+160 - scWidth+1 + scHeight-2 , HeadSc.y+32 - iconsize -5 - scHeight + scHeight-1), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));


    }
    
    
    
         if (wppp == 108005){
             
             
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
//draw->AddImage(WeaponImage[44].textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70
//draw->AddImage(WeaponImage[44].textureId, ImVec2(HeadSc.x+160 - scWidth+1, HeadSc.y+32 - iconsize -5 - scHeight+1), ImVec2(HeadSc.x+160 - scWidth+1 + scHeight-2 , HeadSc.y+32 - iconsize -5 - scHeight + scHeight-1), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));
draw->AddImage(WeaponImage[44].textureId, ImVec2(HeadSc.x+200 - qtWidth+1, HeadSc.y-25 - iconsize -5 - qtHeight+1), ImVec2(HeadSc.x+200 - qtWidth+1 + qtHeight-2 , HeadSc.y-25 - iconsize -5 - qtHeight + qtHeight-1), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));
           
    }
    
    
    
    if (wppp == 101001 ||wppp == 1010011 ||wppp == 1010012 ||wppp == 1010013 ||wppp == 1010014 || wppp == 1010015 || wppp == 1010016 || wppp == 1010017 )
    {
        
        
    TextureInfo textureInfo{};
    textureInfo = ID101001;//AKM
    
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70
//draw->AddImage(textureInfo.textureId, ImVec2(HeadSc.x+160 - scWidth+1, HeadSc.y+32 - iconsize -5 - scHeight+1), ImVec2(HeadSc.x+160 - scWidth+1 + scHeight-2 , HeadSc.y+32 - iconsize -5 - scHeight + scHeight-1), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));

    }
    
    if (wppp == 101002 ||wppp == 1010021 ||wppp == 1010022 ||wppp == 1010023 ||wppp == 1010024 || wppp == 1010025 || wppp == 1010026 || wppp == 1010027 )
    {
    TextureInfo textureInfo{};
textureInfo = ID101002;//M16A4
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70
//draw->AddImage(textureInfo.textureId, ImVec2(HeadSc.x+160 - scWidth+1, HeadSc.y+32 - iconsize -5 - scHeight+1), ImVec2(HeadSc.x+160 - scWidth+1 + scHeight-2 , HeadSc.y+32 - iconsize -5 - scHeight + scHeight-1), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));

    }
    if (wppp == 101003 ||wppp == 1010031 ||wppp == 1010032 ||wppp == 1010033 ||wppp == 1010034 || wppp == 1010035 || wppp == 1010036 || wppp == 1010037 )
    {
    TextureInfo textureInfo{};
textureInfo = ID101003;//SCAR-L
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70
//draw->AddImage(textureInfo.textureId, ImVec2(HeadSc.x+160 - scWidth+1, HeadSc.y+32 - iconsize -5 - scHeight+1), ImVec2(HeadSc.x+160 - scWidth+1 + scHeight-2 , HeadSc.y+32 - iconsize -5 - scHeight + scHeight-1), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));

    }
    if (wppp == 101004 ||wppp == 1010041 ||wppp == 1010042 ||wppp == 1010043 ||wppp == 1010044 || wppp == 1010045 || wppp == 1010046 || wppp == 1010047 )
    {
        
        
        
        
        
    TextureInfo textureInfo{};
textureInfo = ID101004;//M416
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70
//draw->AddImage(textureInfo.textureId, ImVec2(HeadSc.x+160 - scWidth+1, HeadSc.y+32 - iconsize -5 - scHeight+1), ImVec2(HeadSc.x+160 - scWidth+1 + scHeight-2 , HeadSc.y+32 - iconsize -5 - scHeight + scHeight-1), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));

    }
    if (wppp == 101005 ||wppp == 1010051 ||wppp == 1010052 ||wppp == 1010053 ||wppp == 1010054 || wppp == 1010055 || wppp == 1010056 || wppp == 1010057 )
    {
    TextureInfo textureInfo{};
textureInfo = ID101005;//Groza
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70
//draw->AddImage(textureInfo.textureId, ImVec2(HeadSc.x+160 - scWidth+1, HeadSc.y+32 - iconsize -5 - scHeight+1), ImVec2(HeadSc.x+160 - scWidth+1 + scHeight-2 , HeadSc.y+32 - iconsize -5 - scHeight + scHeight-1), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));

    }
        //////
    if (wppp == 101102 ||wppp == 1011021 ||wppp == 1011022 ||wppp == 1011023 ||wppp == 1011024 || wppp == 1011025 ||wppp == 1011026|| wppp == 1011027)
    {
    TextureInfo textureInfo{};
       textureInfo = NACE32; //SOON
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    //////
    if (wppp == 101006 ||wppp == 1010061 ||wppp == 1010062 ||wppp == 1010063 ||wppp == 1010064 || wppp == 1010065 || wppp == 10100166 || wppp == 1010067 )
    {
    TextureInfo textureInfo{};
   textureInfo = ID101006;//AUG A3
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 101007 ||wppp == 1010071 ||wppp == 1010072 ||wppp == 1010073 ||wppp == 1010074 || wppp == 1010075 || wppp == 10100176 || wppp == 1010077 )
    {
    TextureInfo textureInfo{};
  textureInfo = ID101007;//QBZ
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 101008 ||wppp == 1010081 ||wppp == 1010082 ||wppp == 1010083 ||wppp == 1010084 || wppp == 1010085 || wppp == 1010086 || wppp == 1010087 )
    {
    TextureInfo textureInfo{};
textureInfo = ID101008; //M762
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 101009 ||wppp == 1010091 ||wppp == 1010092 ||wppp == 1010093 ||wppp == 1010094 || wppp == 1010095 || wppp == 1010096 || wppp == 1010097 )
    {
    TextureInfo textureInfo{};
  textureInfo = ID101009;//Mk47 
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 101010 ||wppp == 1010101 ||wppp == 1010102 ||wppp == 1010103 ||wppp == 1010104 || wppp == 1010105 || wppp == 1010106 || wppp == 1010107 )
    {
    TextureInfo textureInfo{};
textureInfo = ID101010;//G36C
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 101100 ||wppp == 1011001 ||wppp == 1011002 ||wppp == 1011003 ||wppp == 1011004 || wppp == 1011005 || wppp == 1011006 || wppp == 1011007 )
    {
    TextureInfo textureInfo{};
        //need fix
        textureInfo = NFAMAS; //SOON
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 102001 ||wppp == 1020011 ||wppp == 1020012 ||wppp == 1020013 ||wppp == 1020014 || wppp == 1020015 )
    {
    TextureInfo textureInfo{};
textureInfo = ID102001;//UZI
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 102002 ||wppp == 1020021 ||wppp == 1020022 ||wppp == 1020023 ||wppp == 1020024 || wppp == 1020025 )
    {
    TextureInfo textureInfo{};
textureInfo = ID102002;//UMP45
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 102003 ||wppp == 1020031 ||wppp == 1020032 ||wppp == 1020033 ||wppp == 1020034 || wppp == 1020035 ||wppp == 1020036 ||wppp == 1020037)
    {
    TextureInfo textureInfo{};
textureInfo = ID102003;//Vector
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 102004 ||wppp == 1020041 ||wppp == 1020042 ||wppp == 1020043 ||wppp == 1020044 || wppp == 1020045 ||wppp == 1020046 ||wppp == 1020047)
    {
    TextureInfo textureInfo{};
textureInfo = ID102004;//Tompson SMG
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 102005 ||wppp == 1020051 ||wppp == 1020052 ||wppp == 1020053 ||wppp == 1020054 || wppp == 1020055 ||wppp == 1020056 ||wppp == 1020057)
    {
    TextureInfo textureInfo{};
textureInfo = ID102005;//PP-19 Bizon
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    
    
    if (wppp == 102105 ||wppp == 1021051 ||wppp == 1021052 ||wppp == 1021053 ||wppp == 1021054 || wppp == 1021055 ||wppp == 1021056 ||wppp == 1021057)
    {
    TextureInfo textureInfo{};
textureInfo = ID102105;
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    
        if (wppp == 102007 ||wppp == 1020071 ||wppp == 1020072 ||wppp == 1020073 ||wppp == 1020074 || wppp == 1020075 ||wppp == 1020076 ||wppp == 1020077)
    {
    TextureInfo textureInfo{};
textureInfo = ID102007;//Skorpion
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    
    

    
    if (wppp == 103001 ||wppp == 1030011 ||wppp == 1030012 ||wppp == 1030013 ||wppp == 1030014 || wppp == 1030015 ||wppp == 1030016 ||wppp == 1030017)
    {
    TextureInfo textureInfo{};
 textureInfo = hand.KAR98K;//Kar98K
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 103002 ||wppp == 1030021 ||wppp == 1030022 ||wppp == 1030023 ||wppp == 1030024 || wppp == 1030025 ||wppp == 1030026 ||wppp == 1030027)
    {
    TextureInfo textureInfo{};
textureInfo = ID103002;//M24
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 103003 ||wppp == 1030031 ||wppp == 1030032 ||wppp == 1030033 ||wppp == 1030034 || wppp == 1030035 ||wppp == 1030036|| wppp == 1030037)
    {
    TextureInfo textureInfo{};
textureInfo = ID103003;//AWM
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 103004 ||wppp == 1030041 ||wppp == 1030042 ||wppp == 1030043 ||wppp == 1030044 || wppp == 1030045 ||wppp == 1030046|| wppp == 1030047)
    {
    TextureInfo textureInfo{};
textureInfo = ID103004;//SKS
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 103005 ||wppp == 1030051 ||wppp == 1030052 ||wppp == 1030053 ||wppp == 1030054 || wppp == 1030055 ||wppp == 1030056|| wppp == 1030057)
    {
    TextureInfo textureInfo{};
textureInfo = ID103005;//VSS
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 103006 ||wppp == 1030061 ||wppp == 1030062 ||wppp == 1030063 ||wppp == 1030064 || wppp == 1030065 ||wppp == 1030066|| wppp == 1030067)
    {
    TextureInfo textureInfo{};
textureInfo = ID103006;//Mini14
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 103007 ||wppp == 1030071 ||wppp == 1030072 ||wppp == 1030073 ||wppp == 1030074 || wppp == 1030075 ||wppp == 1030076|| wppp == 1030077)
    {
    TextureInfo textureInfo{};
    textureInfo = ID103007;//Mk14
    FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 103008 ||wppp == 1030081 ||wppp == 1030082 ||wppp == 1030083 ||wppp == 1030084 || wppp == 1030085 ||wppp == 1030086|| wppp == 1030087)
    {
    TextureInfo textureInfo{};
     textureInfo = ID103008;//Win94
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 103009 ||wppp == 1030091 ||wppp == 1030092 ||wppp == 1030093 ||wppp == 1030094 || wppp == 1030095 ||wppp == 1030096|| wppp == 1030097)
    {
    TextureInfo textureInfo{};
textureInfo = hand.SLR; //SLR
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 103010 ||wppp == 1030101 ||wppp == 1030102 ||wppp == 1030103 ||wppp == 1030104 || wppp == 1030105 ||wppp == 1030106|| wppp == 1030107)
    {
    TextureInfo textureInfo{};
textureInfo = ID103010;//QBU
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 103011 ||wppp == 1030111 ||wppp == 1030112 ||wppp == 1030113 ||wppp == 1030114 || wppp == 1030115 ||wppp == 1030116|| wppp == 1030117)
    {
    TextureInfo textureInfo{};
textureInfo = ID103011;//Mosin
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 103012 ||wppp == 1030121 ||wppp == 1030122 ||wppp == 1030123 ||wppp == 1030124 || wppp == 1030125 ||wppp == 1030126|| wppp == 1030127)
     {
    TextureInfo textureInfo{};
textureInfo = ID103012;//Amr
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }

    if (wppp == 103100 ||wppp == 1031001 ||wppp == 1031002 ||wppp == 1031003 ||wppp == 1031004 || wppp == 1031005 ||wppp == 1031006|| wppp == 1031007)
    {
    TextureInfo textureInfo{};
        //needfix
        textureInfo = NMk12;//soon
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 104001 ||wppp == 1040011 ||wppp == 1040012 ||wppp == 1040013 ||wppp == 1040014 || wppp == 1040015 ||wppp == 1040016|| wppp == 1040017)
    {
    TextureInfo textureInfo{};
   textureInfo = ID104001;//S686
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 104002 ||wppp == 1040021 ||wppp == 1040022 ||wppp == 1040023 ||wppp == 1040024 || wppp == 1040025 ||wppp == 1040026|| wppp == 1040027)
    {
    TextureInfo textureInfo{};
  textureInfo = ID104002;//S1897
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 104003 ||wppp == 1040031 ||wppp == 1040032 ||wppp == 1040033 ||wppp == 1040034 || wppp == 1040035 ||wppp == 1040036|| wppp == 1040037)
    {
    TextureInfo textureInfo{};
  textureInfo = ID104003;//S12K
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 104004 ||wppp == 1040041 ||wppp == 1040042 ||wppp == 1040043 ||wppp == 1040044 || wppp == 1040045 ||wppp == 1040046|| wppp == 1040047)
    {
    TextureInfo textureInfo{};
textureInfo = ID104004;//DPS
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 105001 ||wppp == 1050011 ||wppp == 1050012 ||wppp == 1050013 ||wppp == 1050014 || wppp == 1050015 ||wppp == 1050016|| wppp == 1050017)
    {
    TextureInfo textureInfo{};
  textureInfo = ID105001;//M249
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 105002 ||wppp == 1050021 ||wppp == 1050022 ||wppp == 1050023 ||wppp == 1050024 || wppp == 1050025 ||wppp == 1050026|| wppp == 1050027)
    {
    TextureInfo textureInfo{};
    textureInfo = ID105002;//DP-28.
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 106006 ||wppp == 1060061 ||wppp == 1060062 ||wppp == 1060063 ||wppp == 1060064 || wppp == 1060065 ||wppp == 1060066|| wppp == 1060067)
     {
    TextureInfo textureInfo{};
textureInfo = hand.Sawed_off;
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 106001 ||wppp == 1060011 ||wppp == 1060012 ||wppp == 1060013 ||wppp == 1060014 || wppp == 1060015 ||wppp == 1060016|| wppp == 1060017)
     {
    TextureInfo textureInfo{};
textureInfo = hand.P92;
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 106003 ||wppp == 1060031 ||wppp == 1060032 ||wppp == 1060033 ||wppp == 1060034 || wppp == 1060035 ||wppp == 1060036|| wppp == 1060037)
     {
    TextureInfo textureInfo{};
textureInfo = hand.R1895;
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 106004 ||wppp == 1060041 ||wppp == 1060042 ||wppp == 1060043 ||wppp == 1060044 || wppp == 1060045 ||wppp == 1060046|| wppp == 1060047)
     {
    TextureInfo textureInfo{};
textureInfo = hand.P18C;
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 106005 ||wppp == 1060051 ||wppp == 1060052 ||wppp == 1060053 ||wppp == 1060054 || wppp == 1060055 ||wppp == 1060056|| wppp == 1060057)
     {
    TextureInfo textureInfo{};
textureInfo = hand.R45;
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 106008 ||wppp == 1060081 ||wppp == 1060082 ||wppp == 1060083 ||wppp == 1060084 || wppp == 1060085 ||wppp == 1060086|| wppp == 1060087)
    {
    TextureInfo textureInfo{};
        //nerdfix
      textureInfo = NVz61; //SOON
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 106010 ||wppp == 1060101 ||wppp == 1060102 ||wppp == 1060103 ||wppp == 1060104 || wppp == 1060105 ||wppp == 1060106|| wppp == 1060107)
    {
    TextureInfo textureInfo{};
        //needfix
       textureInfo = NDesertEagle;//soon
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 107001 ||wppp == 1070011 ||wppp == 1070012 ||wppp == 1070013 ||wppp == 1070014 || wppp == 1070015 ||wppp == 1070016|| wppp == 1070017)
    {
    TextureInfo textureInfo{};
  textureInfo = ID107001;//CrossBow
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 108001 ||wppp == 1080011 ||wppp == 1080012 ||wppp == 1080013 ||wppp == 1080014 || wppp == 1080015 ||wppp == 1080016|| wppp == 1080017)
    {
    TextureInfo textureInfo{};
    textureInfo = ID大砍刀;
    FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 108002 ||wppp == 1080021 ||wppp == 1080022 ||wppp == 1080023 ||wppp == 1080024 || wppp == 1080025 ||wppp == 1080026|| wppp == 1080027)
    {
    TextureInfo textureInfo{};
    textureInfo = ID撬棍;
    FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 108003 ||wppp == 1080031 ||wppp == 1080032 ||wppp == 1080033 ||wppp == 1080034 || wppp == 1080035 ||wppp == 1080036|| wppp == 1080037)
    {
    TextureInfo textureInfo{};
    textureInfo = ID镰刀;
    FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 108004 ||wppp == 1080041 ||wppp == 1080042 ||wppp == 1080043 ||wppp == 1080044 || wppp == 1080045 ||wppp == 1080046|| wppp == 1080047)
    {
    TextureInfo textureInfo{};
     textureInfo = hand.PAN;//Pan
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 106002 ||wppp == 1060021 ||wppp == 1060022 ||wppp == 1060023 ||wppp == 1060024 || wppp == 1060025 ||wppp == 1060026|| wppp == 1060027)
    {
    TextureInfo textureInfo{};
    textureInfo = hand.P1911;
    FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    
        if (wppp == 602004)
    {
    TextureInfo textureInfo{};
  textureInfo = ID手雷弹;
  FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 602002)
    {
    TextureInfo textureInfo{};
  textureInfo = ID烟雾弹;
  FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 602001)
    {
    TextureInfo textureInfo{};
   textureInfo = ID震撼弹;
   FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    if (wppp == 602003)
    {
    TextureInfo textureInfo{};
  textureInfo = ID燃烧瓶;
  FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70

    }
    

    }else{

                   TextureInfo textureInfo{};
textureInfo = ID拳头;
FVector2D ImageHeadSc;
    WorldToScreenBone(Head, (FVector2D *)& ImageHeadSc);
    ImVec4 rect((ImageHeadSc.X) - 80, ImageHeadSc.Y - 50, 160, 25);//50
draw->AddImage(textureInfo.textureId, {ImageHeadSc.X + 50, rect.y  - 41}, {ImageHeadSc.X - 70, rect.y  - 0});//70


    }
    
    
    }}
   
                
                
    
    
    if (Config.Distance) {
                std::string str = std::to_string((int) Distance);    
                str += " m";
                auto textSizes = ImGui::CalcTextSize(str.c_str(), 0, 35);
             //   draw->AddText(NULL, 25, {RootSc.X - (textSizes.x / 2), RootSc.Y + 15}, ImColor(255,200,0,255), str.c_str());
                Fly_Draw->DrawStrokeText(RootSc.x - (textSizes.x / 2), RootSc.y + 15, ImColor(255,200,0,255), str.c_str());
                
            }
                            
 
}






}

}

  
      if (isObjectInvalid(Actors[i]))
                                continue;
  
         if (Config.GrenadeW) {
                                      if (isObjectGrenade(Actors[i])) {
               auto *Grenade = (ASTExtraGrenadeBase *) Actors[i];
                                std::string n = getObjectPath(Grenade);
                                auto RootComponent = Actors[i]->RootComponent;
                                if (!RootComponent)
                                    continue;
                                float Distance = Grenade->GetDistanceTo(localPlayer) / 100.f;

      FVector2D Location;
    if (WorldToScreenBone(Grenade->K2_GetActorLocation(), &Location)) {
                if (Distance <= 100.f) {
                    

                                    std::string s;
                          
                                      if(n=="BP_Grenade_Burn_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object" || n=="BP_Grenade_Shoulei_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object"){

                            
draw->AddText(Chinese, 50/* ((float) density / 6.0f)*/, ImVec2(glWidth / 2 - 112, 250), IM_COL32(255, 0, 0, 255), "WARNING...!!!");

                            
                                    }
                                    if(n=="BP_Grenade_Burn_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object"){
                                        
                                        s+="Molotov";
                                           s += " - [";
                                    s += std::to_string((int) Distance);
                                    s += "M]";
                                    } else if(n=="BP_Grenade_Shoulei_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object"){
                                     //   m_Canvas->drawText(OBFUSCATE("⚠️ WARNING ⚠️"), screenWidth / 2, 195, 35.f, Align::CENTER, skeletonByDistance(Distance), BLACK);
              
                                        s+="Grenade";
                                           s += " - [";
                                    s += std::to_string((int) Distance);
                                    s += "M]";
                                    }
                                 draw->AddText(nullptr, 30/* ((float) density / 6.0f)*/, ImVec2(Location.X, Location.Y), IM_COL32(255, 0, 0, 255), s.c_str());


                    
                                               
                                           }
                                                  
                                }
                            }
                        }
        
        
           if (isObjectLoot(Actors[i])) {
                    auto *PickUp = (APickUpWrapperActor *) Actors[i];
  
  
                                int wppp =0;
                                std::string classname = PickUp->GetName();
                                 if (classname.empty());
                                        
                            auto RootComponent = PickUp->RootComponent;
                            if (!RootComponent)
                                continue;

                            float Distance = PickUp->GetDistanceTo(localPlayer) / 100.f;

                               wppp = PickUp->DefineID.TypeSpecificID;
                             //   FVector Location = RootComponent->RelativeLocation;       
                             int m4 = 0xFFD1EEEE;
                                    int ak = 0xFFFCC89D;
                                    int lvmax = 0xFFFFF266;
                                    int smg = 0xFF919AFF;
                                    int smg2 = 0xFFF8FAB9;
                                    int smg3 = 0xFFFCC89D;
                                    int sniper = 0xFFFCC89D;
                                    int mi = 0xFFD1EEEE;
                                    int wi = 0xFFF8FAB9;
                                    int medic = 0xFF4DFF76;
                                    int sight = 0xFF9FBD1C;
                                    int mag = 0xFF9FBD1C;
                                    int suppr = 0xFF9FBD1C;
                                    FVector2D Location;
                           if (WorldToScreenBone(PickUp->K2_GetActorLocation(), &Location)) {

                                std::string s;
                                if (Distance <= 100.f) {
    
                                
                                
                             
                                 if (Config.M416) {
                            if (wppp == 101004 ||wppp == 1010041 ||wppp == 1010042 ||wppp == 1010043 ||wppp == 1010044 || wppp == 1010045 || wppp == 1010046 || wppp == 1010047 ) {
                                s += "M416";
                                 s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, m4, s.c_str());
                       
                                   }
                            }
    
                                  if (Config.AKM) {
    if (wppp == 101001 ||wppp == 1010011 ||wppp == 1010012 ||wppp == 1010013 ||wppp == 1010014 || wppp == 1010015 || wppp == 1010016 || wppp == 1010017 ) {
                                s += "AKM";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, ak, s.c_str());
                       
                                
        
    }
    }

    
          if (Config.SCARL) {
    if (wppp == 101003 ||wppp == 1010031 ||wppp == 1010032 ||wppp == 1010033 ||wppp == 1010034 || wppp == 1010035 || wppp == 1010036 || wppp == 1010037 )
    {
                                s += "SCAR-L";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, m4, s.c_str());
                       
                                
       
    }
    }
    
     if (Config.ACE32) {
        if (wppp == 101102 ||wppp == 1011021 ||wppp == 1011022 ||wppp == 1011023 ||wppp == 1011024 || wppp == 1011025 ||wppp == 1011026|| wppp == 1011027)
    {
                                s += "ACE32";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, ak, s.c_str());
                        
                     
        
    }
    }
    
    
       if (Config.Groza) {

    if (wppp == 101005 ||wppp == 1010051 ||wppp == 1010052 ||wppp == 1010053 ||wppp == 1010054 || wppp == 1010055 || wppp == 1010056 || wppp == 1010057 )  {
   
        
                                s += "Groza";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                       draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, ak, s.c_str());
                       
    }}
    
    if (Config.AUG) {

    if (wppp == 101006 ||wppp == 1010061 ||wppp == 1010062 ||wppp == 1010063 ||wppp == 1010064 || wppp == 1010065 || wppp == 10100166 || wppp == 1010067 )
    {
        
                                s += "AUG";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, m4, s.c_str());
                       
        
    }
    }
    
    
        if (Config.QBZ) {
        if (wppp == 101007 ||wppp == 1010071 ||wppp == 1010072 ||wppp == 1010073 ||wppp == 1010074 || wppp == 1010075 || wppp == 10100176 || wppp == 1010077 )
    { 
                                s += "QBZ";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, m4, s.c_str());
                       
        
    }
    }
    
    
         if (Config.M762) {
    if (wppp == 101008 ||wppp == 1010081 ||wppp == 1010082 ||wppp == 1010083 ||wppp == 1010084 || wppp == 1010085 || wppp == 1010086 || wppp == 1010087 ) {
                           s += "M762";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                                draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, ak, s.c_str());
                         

        
    }
    }

     if (Config.G36C) {
    if (wppp == 101010 ||wppp == 1010101 ||wppp == 1010102 ||wppp == 1010103 ||wppp == 1010104 || wppp == 1010105 || wppp == 1010106 || wppp == 1010107 )
    {
  
              s += "G36C";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                                draw->AddText(NULL, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, ak, s.c_str());
                       

        
    }
    }
     if (Config.FAMAS) {
    if (wppp == 101100 ||wppp == 1011001 ||wppp == 1011002 ||wppp == 1011003 ||wppp == 1011004 || wppp == 1011005 || wppp == 1011006 || wppp == 1011007 )
    {
              s += "FAMAS";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(NULL,30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, m4, s.c_str());
                        

    }
    }
    
      if (Config.M249) {
        if (wppp == 105001 ||wppp == 1050011 ||wppp == 1050012 ||wppp == 1050013 ||wppp == 1050014 || wppp == 1050015 ||wppp == 1050016|| wppp == 1050017)
    {
             s += "M249";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(NULL, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, m4, s.c_str());
                       

        
    }
    }
      if (Config.DP28) {
    if (wppp == 105002 ||wppp == 1050021 ||wppp == 1050022 ||wppp == 1050023 ||wppp == 1050024 || wppp == 1050025 ||wppp == 1050026|| wppp == 1050027)
    {

             s += "DP-28";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                                draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, ak, s.c_str());
                       

        
    }
    }
                                  
                                   
    
                                   
                                   
                                   
                                                 if (Config.UZI) {
                                
    if (wppp == 102001 ||wppp == 1020011 ||wppp == 1020012 ||wppp == 1020013 ||wppp == 1020014 || wppp == 1020015 ) {//
            s += "UZI";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(nullptr,30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, smg, s.c_str());
                       

  
        
        
    }
    }
    
          if (Config.UMP45) {
                                
    if (wppp == 102002 ||wppp == 1020021 ||wppp == 1020022 ||wppp == 1020023 ||wppp == 1020024 || wppp == 1020025 )
    {//
          s += "UMP-45";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, smg, s.c_str());
                       

  
    }
    }
    
      if (Config.Vector) {
    if (wppp == 102003 ||wppp == 1020031 ||wppp == 1020032 ||wppp == 1020033 ||wppp == 1020034 || wppp == 1020035 ||wppp == 1020036 ||wppp == 1020037)
    {//
             s += "Vector";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, smg, s.c_str());
                       

  
    }
    }
    
    
    
       if (Config.TommyGun) {
    if (wppp == 102004 ||wppp == 1020041 ||wppp == 1020042 ||wppp == 1020043 ||wppp == 1020044 || wppp == 1020045 ||wppp == 1020046 ||wppp == 1020047)
    {//
         s += "TommyGun";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, smg, s.c_str());
                       

  
    }
    }
    
       if (Config.PP19Bizon) {
    if (wppp == 102005 ||wppp == 1020051 ||wppp == 1020052 ||wppp == 1020053 ||wppp == 1020054 || wppp == 1020055 ||wppp == 1020056 ||wppp == 1020057)
    {//
          s += "PP-19 Bizon";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, smg, s.c_str());
                       

  
    }
    }
    
    
       if (Config.P90) {
    if (wppp == 102105 ||wppp == 1021051 ||wppp == 1021052 ||wppp == 1021053 ||wppp == 1021054 || wppp == 1021055 ||wppp == 1021056 ||wppp == 1021057)
    {//
       s += "P90";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, smg, s.c_str());
                           

  
    }
    }
    
       if (Config.Skorpion) {
        if (wppp == 102007 ||wppp == 1020071 ||wppp == 1020072 ||wppp == 1020073 ||wppp == 1020074 || wppp == 1020075 ||wppp == 1020076 ||wppp == 1020077)
    {//
       s += "Skorpion";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, smg, s.c_str());
                       
  
    }
    }
    
    
    
                            
                                     
                                   if (Config.Kar98K) {
    if (wppp == 103001 ||wppp == 1030011 ||wppp == 1030012 ||wppp == 1030013 ||wppp == 1030014 || wppp == 1030015 ||wppp == 1030016 ||wppp == 1030017)
    {
           s += "Kar98K";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, sniper, s.c_str());
                       

  
    }
    }
         if (Config.M24) {
    if (wppp == 103002 ||wppp == 1030021 ||wppp == 1030022 ||wppp == 1030023 ||wppp == 1030024 || wppp == 1030025 ||wppp == 1030026 ||wppp == 1030027) {
                   s += "M24";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, sniper, s.c_str());
                         

    }
    }
       if (Config.AWM) {
    if (wppp == 103003 ||wppp == 1030031 ||wppp == 1030032 ||wppp == 1030033 ||wppp == 1030034 || wppp == 1030035 ||wppp == 1030036|| wppp == 1030037)
    {
                   s += "AWM";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(nullptr,30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, sniper, s.c_str());
                       
    }}
     if (Config.AMR) {
       if (wppp == 103012 ||wppp == 1030121 ||wppp == 1030122 ||wppp == 1030123 ||wppp == 1030124 || wppp == 1030125 ||wppp == 1030126|| wppp == 1030127)
    {
   
                           s += "AMR";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, sniper, s.c_str());
                       
        
    }}
                                         
                                     if (Config.mm556) {
                                      
                                     
    
    if (wppp == 303001 ||wppp == 3030011 ||wppp == 3030012 ||wppp == 3030013 ||wppp == 3030014 || wppp == 3030015 ||wppp == 3030016)
    {
           s += "5.56mm";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, m4, s.c_str());
                       

  
                             
                       
    }
            }
    if (Config.mm762) {
                                      
    if (wppp == 302001 ||wppp == 3020011 ||wppp == 3020012 ||wppp == 3020013 ||wppp == 3020014 || wppp == 3020015 ||wppp == 3020016)
    {
           s += "7.62mm";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, ak, s.c_str());
                        

  
                             
                       
    }}
                                      
                                       
                                       
                                            
                                         if (Config.mm9) {
                                      
    
    if (wppp == 301001 ||wppp == 3010011 ||wppp == 3010012 ||wppp == 3010013 ||wppp == 3010014 || wppp == 3010015 ||wppp == 3010016)
    {
           s += "9mm";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(NULL, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, smg, s.c_str());
                       

  
                             
                        //    .45 ACP
    }
    }
    
        if (Config.ACP45) {
                                      
        if (wppp == 305001 ||wppp == 3050011 ||wppp == 3050012 ||wppp == 3050013 ||wppp == 3050014 || wppp == 3050015 ||wppp == 3050016)
    {
           s += ".45 ACP";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(NULL, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, smg, s.c_str());
                        

  
                             
                        //    
    }
                    }
                                      
                                       
                                         if (Config.Bag) {
                             
    
    if (wppp == 501006 ||wppp == 501103 ||wppp == 501104 ||wppp == 501105 ||wppp == 501106)
    {
           s += "Bag";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(NULL, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, lvmax, s.c_str());
                        
                            
    }                  
                                       
                                       }//Bag(lv,3.4.5.6)        
                                       
                                       
                                       
                                           if (Config.Armor) {
                             
    
    if (wppp == 503003 ||wppp == 503103 ||wppp == 503104 ||wppp == 503105 ||wppp == 503106 ||wppp == 503107 ||wppp == 503108 ||wppp == 503109 ||wppp == 503110 ||wppp == 503111 ||wppp == 503112)
    {
           s += "Armor";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
draw->AddText(NULL, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, lvmax, s.c_str());
                       
    }                  
                                       
                                       }//Armor(lv,3.4.5.6)        
                                       
                            
                                            if (Config.Helmet) {
                             
    
    if (wppp == 502003 ||wppp == 502103 ||wppp == 502104 ||wppp == 502105 ||wppp == 502106 ||wppp == 502107 ||wppp == 502108 ||wppp == 502109 ||wppp == 502110 ||wppp == 502111 ||wppp == 502112)
    {
           s += "Helmet";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            draw->AddText(NULL, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, lvmax, s.c_str());
                         
                            
    }                  }
                                       
                                       }//Armor(lv,3.4.5.6)     
                                       
                                       
                            }
                        }
                        

                if (isObjectLootBox(Actors[i])) {
                auto *PickUpList = (APickUpListWrapperActor *) Actors[i];
  
  
  
                                   if (Config.EspLootBox) {
              //  APickUpListWrapperActor *PickUpList = (APickUpListWrapperActor *) Actors[i];
                auto PickUpDataList = (TArray<FPickUpItemData>) PickUpList->GetDataList();
                auto RootComponent = PickUpList->RootComponent;
            if (!RootComponent)
                continue;
                FVector2D Location;
    if (WorldToScreenBone(PickUpList->K2_GetActorLocation(), &Location)) {
            float Distance = PickUpList->GetDistanceTo(localPlayer) / 100.f;    
            if (Distance <= 50.f) {
                std::string s = "Box";  
                s += " [";
                s += std::to_string((int) Distance);
                s += "m]";

                     draw->AddText(NULL, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, IM_COL32(0, 255, 0, 255), s.c_str());
                       }
                        }
                        
                        }
                    }
                    

     if (isObjectVehicle(Actors[i])) {
                auto *Vehicle = (ASTExtraVehicleBase *) Actors[i];
                
                  if (Config.EspCar) {
              //  ASTExtraVehicleBase *Vehicle = (ASTExtraVehicleBase *) Actors[i];
                auto RootComponent = Vehicle->RootComponent;
                if (!RootComponent)
                    continue;

                    float vDistance = Vehicle->GetDistanceTo(localPlayer) / 100.f;
           //     if (vDistance < 700.f) {
                 //   FVector Location = WorldToScreen(RootComponent->RelativeLocation);
              //  if (Location.Z > 0) {
                  FVector2D Location;
    if (WorldToScreenBone(Vehicle->K2_GetActorLocation(), &Location)) {
                    std::string s = GetVehicleName(Vehicle);                                
                    s += " - ";
                    s += std::to_string((int) vDistance);
                    s += "M";
                 //   auto mText = m_Canvas->getTextBounds(s.c_str(), 0, s.size());
                             draw->AddText(nullptr, 30/*((float) density / 25.0f)*/,{Location.X, Location.Y}, IM_COL32(255,50,255,255), s.c_str());
             

                    }
                }
            }
        
                    
                    }
                }

            
{
    
    
      draw->AddImage(Base64Image[1].textureId, ImVec2(glWidth / 2-115 - 50 / 2, 115), ImVec2(glWidth / 2-115 + 50 / 2, 115 + 50), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));
        draw->AddImage(Base64Image[2].textureId, ImVec2(glWidth / 2+115 - 50 / 2, 115), ImVec2(glWidth / 2+115 + 50 / 2, 115 + 50), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));
         if (totalEnemies == 0 && totalBots == 0) {
        draw->AddImage(Base64Image[3].textureId, ImVec2(glWidth / 2 - 50 / 2, 114), ImVec2(glWidth / 2 + 50 / 2, 114 + 50), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));
         }else{
         
        if(totalBots == 0){
            draw->AddTextX(ImVec2(glWidth / 2 + 36.5, 101.5 + 50 / 2 - 5), ImColor(0, 0, 0, 255),45, std::to_string(totalBots).c_str());
                draw->AddTextX(ImVec2(glWidth / 2 + 35, 100 + 50 / 2 - 5), ImColor(0, 255, 0), 45, std::to_string(totalBots).c_str());
           }else{
        draw->AddTextX(ImVec2(glWidth / 2 + 36.5, 101.5 + 50 / 2 - 5), ImColor(0, 0, 0, 255),45, std::to_string(totalBots).c_str());
                draw->AddTextX(ImVec2(glWidth / 2 + 35, 100 + 50 / 2 - 5), ImColor(255, 255, 0), 45, std::to_string(totalBots).c_str());
                draw->AddImage(Base64Image[4].textureId, ImVec2(glWidth / 2 - 50 / 2, 114), ImVec2(glWidth / 2 + 50 / 2, 114 + 50), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));
        }
         if(totalEnemies == 0){
             draw->AddTextX(ImVec2(glWidth / 2 - calcTextSize(std::to_string(totalEnemies).c_str(), 40) - 33.5, 101.5 + 50 / 2 - 5), ImColor(0, 0, 0, 255), 45, std::to_string(totalEnemies).c_str());
                draw->AddTextX(ImVec2(glWidth / 2 - calcTextSize(std::to_string(totalEnemies).c_str(), 40) - 35, 100 + 50 / 2 - 5), ImColor(0, 255, 0), 45, std::to_string(totalEnemies).c_str());
                  }else{
                      draw->AddTextX(ImVec2(glWidth / 2 - calcTextSize(std::to_string(totalEnemies).c_str(), 40) - 33.5, 101.5 + 50 / 2 - 5), ImColor(0, 0, 0, 255), 45, std::to_string(totalEnemies).c_str());
                draw->AddTextX(ImVec2(glWidth / 2 - calcTextSize(std::to_string(totalEnemies).c_str(), 40) - 35, 100 + 50 / 2 - 5), ImColor(255, 0, 0), 45, std::to_string(totalEnemies).c_str());
                draw->AddImage(Base64Image[5].textureId, ImVec2(glWidth / 2 - 50 / 2, 114), ImVec2(glWidth / 2 + 50 / 2, 114 + 50), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f));
                      }
        }


}

}}

  if (Config.AimEnable){
        if (!Config.HideFov){
draw->AddCircle(ImVec2(glWidth / 2, glHeight / 2), Config.AimFov,IM_COL32(255, 255, 255, 255), 10000, 2.0f);
}}

  }
  
  
     
     {
         draw->AddTextX(ImVec2(glWidth / 2 - calcTextSize( "BEAR-MOD", 23.5f) - 3.5, 101.5 + 50 / 2 + 50), ImColor(0, 0, 0, 255),50, "BEAR-MOD");
        draw->AddTextX(ImVec2(glWidth / 2 - calcTextSize( "BEAR-MOD", 23.5f) - 5, 100 + 50 / 2 + 50), ImColor(255, 255, 255), 50, "BEAR-MOD");
         
         
     }
  }}
