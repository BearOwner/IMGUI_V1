
const char *GetVehicleName(ASTExtraVehicleBase *Vehicle) {
    switch (Vehicle->VehicleShapeType) {
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike_SideCart:
            return "Motorbike";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Dacia:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyDacia:
            return "Dacia";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MiniBus:
            return "Mini Bus";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyPickup:
            return "Pick Up";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Buggy:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyBuggy:
            return "Buggy";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ02:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ03:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUAZ:
            return "UAZ";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PG117:
            return "PG117";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Aquarail:
            return "Aquarail";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado01:
            return "Mirado";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Rony:
            return "Rony";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Scooter:
            return "Scooter";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowMobile:
            return "Snow Mobile";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_TukTukTuk:
            return "Tuk Tuk";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowBike:
            return "Snow Bike";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Surfboard:
            return "Surf Board";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Snowboard:
            return "Snow Board";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Amphibious:
            return "Amphibious";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_LadaNiva:
            return "Lada Niva";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAV:
            return "UAV";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MegaDrop:
            return "Mega Drop";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini01:
            return "Lamborghini";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_GoldMirado:
            return "Gold Mirado";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_BigFoot:
            return "Big Foot";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UH60:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUH60:
            return "UH60";
        default:
            return "Vehicle";
    }
}

#define E(str) _xor_(str).c_str()

std::wstring utf8_to_wstring (const std::string& str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    return myconv.from_bytes(str);
}

std::string wstring_to_utf8 (const std::wstring& str)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    return myconv.to_bytes(str);
}

FVector WorldToRadar(float Yaw, FVector Origin, FVector LocalOrigin, float PosX, float PosY, Vector3 Size, bool &outbuff) {
 bool flag = false;
 double num = (double)Yaw;
 double num2 = num * 0.017453292519943295;
 float num3 = (float)std::cos(num2);
 float num4 = (float)std::sin(num2);
 float num5 = Origin.X - LocalOrigin.X;
 float num6 = Origin.Y - LocalOrigin.Y;
 struct FVector Xector;
 Xector.X = (num6 * num3 - num5 * num4) / 150.f;
 Xector.Y = (num5 * num3 + num6 * num4) / 150.f;
 struct FVector Xector2;
 Xector2.X = Xector.X + PosX + Size.X / 2.f;
 Xector2.Y = -Xector.Y + PosY + Size.Y / 2.f;
 bool flag2 = Xector2.X > PosX + Size.X;
 if (flag2) {
  Xector2.X = PosX + Size.X;
 }else{
  bool flag3 = Xector2.X < PosX;
  if (flag3) {
   Xector2.X = PosX;
  }
 }
 bool flag4 = Xector2.Y > PosY + Size.Y;
 if (flag4) {
  Xector2.Y = PosY + Size.Y;
 }else{
  bool flag5 = Xector2.Y < PosY;
  if (flag5){
   Xector2.Y = PosY;
  }
 }
 bool flag6 = Xector2.Y == PosY || Xector2.X == PosX;
 if (flag6){
  flag = true;
 }
 outbuff = flag;
 return Xector2;
}

#define IM_PI                   3.14159265358979323846f
#define RAD2DEG(x) ((float)(x) * (float)(180.f / IM_PI))
#define DEG2RAD(x) ((float)(x) * (float)(IM_PI / 180.f))
void VectorAnglesRadar(Vector3 & forward, FVector & angles) {
    if (forward.X == 0.f && forward.Y == 0.f) {
        angles.X = forward.Z > 0.f ? -90.f : 90.f;
        angles.Y = 0.f;
    } else {
        angles.X = RAD2DEG(atan2(-forward.Z, forward.Magnitude(forward)));
        angles.Y = RAD2DEG(atan2(forward.Y, forward.X));
    }
    angles.Z = 0.f;
}
float DanceValue = 0.0f; 

// ======================================================= \\
#define E(str) _xor_(str).c_str()
#define COLOR_BLACK FLinearColor(0, 0, 0, 1.f)
#define COLOR_WHITE FLinearColor(1.f, 1.f, 1.f, 1.f)
#define COLOR_RED FLinearColor(1.f, 0, 0, 1.f)
#define COLOR_CAR FLinearColor(1.f, 0.5f, 1.f, 1.f)
#define COLOR_GREEN FLinearColor(0, 0.5f, 0, 1.f)
#define COLOR_ORANGE FLinearColor(1.f, 0.4f, 0, 1.f)
#define COLOR_YELLOW FLinearColor(1.f, 1.f, 0, 1.f)
#define COLOR_LIME FLinearColor(0, 1.f, 0, 1.f)
#define COLOR_BLUE FLinearColor(0, 0, 1.f, 1.f)
#define COLOR_THISTLE FLinearColor(1.0f, 0.74f, 0.84f, 1.0f)

#define COLOR_RED2 FLinearColor(1.f, 0, 0, 0.390f)//400f
#define COLOR_LIME2 FLinearColor(0, 1.f, 0, 0.390f)

uint32_t Colors33[] = {0x53BB0C, 0x530826, 0x0FC3F4, 0xDC2855, 0x0A31DE, 0xBAA7FD, 0xCEDB3F, 0x286A45, 0x58F014, 0x45CAE6, 0x773702, 0xB0CEF0, 0x3C5F51, 0x453CD7, 0x364024, 0x439997, 0x4CB612, 0xC6B564, 0x17F250, 0xE41BC0, 0xAF8E27, 0x8E382E, 0x47A101, 0x9DAC33, 0x66F4CF, 0x59A9F0, 0x798D1A, 0x2EBB59, 0xBF66C3, 0x4BD8FB, 0xBBFA54, 0x6B9881, 0x144967, 0xBAA3AE, 0xE80B9D, 0x7BA552, 0x96A456, 0x17D7B4, 0x130C39, 0x3C06A8, 0x62737E, 0xA87E89, 0xB6D3E4, 0x66B77D, 0x66E304, 0x1B80E1, 0x7A06BC, 0xBFFB1B, 0x618506, 0x7E4D34};

FLinearColor GetRandomColorByIndexHud(int index) {
    srand(index);

    
    float a = 170;//255
    float r = ((Colors33[rand() % sizeof(Colors33)] & 0xFF0000) >> 16);
    float g = ((Colors33[rand() % sizeof(Colors33)] & 0x00FF00) >> 8);
    float b = (Colors33[rand() % sizeof(Colors33)] & 0x0000FF);

   // return {r, g, b, a};
    return {r / 255, g / 255, b / 255, a / 255};//255
}

FLinearColor GetRandomColorByIndexHud2(int index) {
    srand(index);

    
    float a = 255;//255
    float r = ((Colors33[rand() % sizeof(Colors33)] & 0xFF0000) >> 16);
    float g = ((Colors33[rand() % sizeof(Colors33)] & 0x00FF00) >> 8);
    float b = (Colors33[rand() % sizeof(Colors33)] & 0x0000FF);

   // return {r, g, b, a};
    return {r / 255, g / 255, b / 255, a / 255};//255
}

void DrawRectangle(AHUD *HUD, FVector2D Pos, float Width, float Height, float Thickness, FLinearColor Color) {
    HUD->DrawLine(Pos.X, Pos.Y, Pos.X + Width, Pos.Y, Color, Thickness);
    HUD->DrawLine(Pos.X, Pos.Y, Pos.X, Pos.Y + Height, Color, Thickness);
    HUD->DrawLine(Pos.X + Width, Pos.Y, Pos.X + Width, Pos.Y + Height, Color, Thickness);
    HUD->DrawLine(Pos.X, Pos.Y + Height, Pos.X + Width, Pos.Y + Height, Color, Thickness);
}

void DrawFilledRectangle(AHUD *HUD, FVector2D Pos, float Width, float Height, FLinearColor Color) {
    HUD->DrawRect(Color, Pos.X, Pos.Y, Width, Height);
}

void DrawFilledRectangle2(AHUD *HUD, FVector2D Pos, FVector2D Pos2, FLinearColor Color) {
    HUD->DrawRect(Color, Pos.X, Pos.Y, Pos2.X, Pos2.Y);
}

void DrawLine(AHUD *HUD, FVector2D posFrom, FVector2D posTo, float Thickness, FLinearColor Color) {
    HUD->DrawLine(posFrom.X, posFrom.Y, posTo.X, posTo.Y, Color, Thickness);
}
/*
void DrawBoxEnemy(AHUD *HUD, FVector2D X, FVector2D Y, float Thickness, FLinearColor Color) {
    HUD->DrawLine({X.X, Y.Y}, {X.X, Y.Y}, Color, Thickness);
}

*/
void DrawBoxEnemy(AHUD *HUD, FVector2D X, FVector2D Y, float thicc, float rounding, FLinearColor Color) {
    UCanvas *Canvas = HUD->Canvas;
    
    Canvas->K2_DrawLine({X.X, X.Y}, {Y.X, Y.Y},  thicc, Color);
       
    //DebugCanvas->K2_DrawLine(FVector2D({posFrom.X, posFrom.Y}), FVector2D({posTo.X, posTo.Y}), Thickness, Color);

}

void DrawBoxEnemy(AHUD *HUD, FVector2D X, FVector2D Y, float thicc, FLinearColor Color) {
    UCanvas *Canvas = HUD->Canvas;
    
    Canvas->K2_DrawLine({X.X, X.Y}, {Y.X, Y.Y},  thicc, Color);
       
    }

void DrawBoxEnemy2(AHUD *HUD, FVector2D X, FVector2D Y, float thicc, FLinearColor Color) {
    UCanvas *Canvas = HUD->Canvas;
    
    Canvas->K2_DrawLine({X.X, X.Y}, {Y.X, Y.Y},  thicc, Color);
       
    }

/*
void DrawBoxEnemy(ImDrawList *draw, ImVec2 X, ImVec2 Y, float thicc, float rounding, int color) {
    draw->AddLine({X.x, X.y}, {Y.x, Y.y}, color, thicc);
}
void DrawBoxEnemy(ImDrawList *draw, ImVec2 X, ImVec2 Y, float thicc, int color) {
    draw->AddLine({X.x, X.y}, {Y.x, Y.y}, color, thicc);
}
*/



void DrawLine2(AHUD *HUD, FVector2D posFrom, FVector2D posTo, float Thickness, FLinearColor Color) {
//    HUD->DrawLine(posFrom.X, posFrom.Y, posTo.X, posTo.Y, Color, Thickness);
    UCanvas *DebugCanvas = HUD->DebugCanvas;
    
    DebugCanvas->K2_DrawLine(FVector2D({posFrom.X, posFrom.Y}), FVector2D({posTo.X, posTo.Y}), Thickness, Color);

}
 


void DrawFilledRect(AHUD *HUD, FVector2D initial_pos, float w, float h, FLinearColor Color)
{
    UCanvas *Canvas = HUD->Canvas;
    for (float i = 0.f; i < h; i += 1.f)
        Canvas->K2_DrawLine(FVector2D(initial_pos.X, initial_pos.Y + i), FVector2D(initial_pos.X + w, initial_pos.Y + i), 1.f, Color);
    
}

void DrawRectanglegg(AHUD * HUD, FVector2D Pos, float Width, float Height, float Thickness,
                   FLinearColor Color)
{
    HUD->DrawLine(Pos.X, Pos.Y, Pos.X + Width, Pos.Y, Color, Thickness);
    HUD->DrawLine(Pos.X, Pos.Y, Pos.X, Pos.Y + Height, Color, Thickness);
    HUD->DrawLine(Pos.X + Width, Pos.Y, Pos.X + Width, Pos.Y + Height, Color, Thickness);
    HUD->DrawLine(Pos.X, Pos.Y + Height, Pos.X + Width, Pos.Y + Height, Color, Thickness);
}
void DrawFilledRectanglejjj(AHUD *HUD, FVector2D Pos, float Width, float Height, FLinearColor Color) {
    HUD->DrawRect(Color, Pos.X, Pos.Y, Width, Height);
    for (size_t i = 0; i <5; i++)
        HUD->  DrawRect(FLinearColor(255, 81, 75, 61), Pos.X + (i *2), Pos.Y, 1, 6);
}
void HealthBar(AHUD *HUD, ASTExtraCharacter* pEntity, float x, float y, float height ,FLinearColor color)
{
    float flBoxes = std::ceil( pEntity->Health / 10.f );
    float flX = x - 7 - height / 3.f; float flY = y - 1;
    float flHeight = height / 10.f;
    float flMultiplier = 12 / 360.f; flMultiplier *= flBoxes - 1;
    HUD->DrawRect( color,flX, flY, 4, height + 2 );
    DrawRectanglegg(HUD,  flX, flY, 4, height + 2, color);
    HUD->DrawRect(color,flX + 1, flY, 2, flHeight * flBoxes + 1 );
    for ( int i = 0; i < 10; i++ )
        HUD->DrawLine( flX, flY + i * flHeight, flX + 4, flY + i * flHeight ,color,1.f);
}

void HealthBarnew( AHUD *HUD,float Health, float x, float y, int height )
{
    float flBoxes = std::ceil( Health / 10.f );
    float flX = x - 7 - height / 3.f; float flY = y - 1;
    float flHeight = height / 10.f;
    float flMultiplier = 12 / 360.f; flMultiplier *= flBoxes - 1;
    //FLinearColor  ColHealth =( flMultiplier, 1, 1 );
    DrawRectanglegg( HUD,flX, flY, 4, height + 2, COLOR_YELLOW );
    DrawFilledRectanglejjj(HUD,{flX, flY}, 4, height + 2, COLOR_BLACK);
    DrawRectanglegg( HUD,flX + 1, flY, 2, flHeight * flBoxes + 1, COLOR_RED );
}

void DrawFilledCircleM2(AHUD *HUD, FVector2D pos, float r, FLinearColor color)
    {
        
        
    UCanvas *DebugCanvas = HUD->DebugCanvas;
        float smooth = 0.07f;

#define PI 3.14159265358979323846

      //  double PI = 3.14159265359;
      double PIGG = 3.14159265359;
      
        int size = (int)(2.0f * PIGG / smooth) + 1;

        float angle = 0.0f;
        int i = 0;

        for (; angle < 2 * PI; angle += smooth, i++)
        {
            
            DebugCanvas->K2_DrawLine(FVector2D(pos.X, pos.Y), FVector2D(pos.X + cosf(angle) * r, pos.Y + sinf(angle) * r ), 1.f, color);

          //  Draw_Line(FVector2D{ pos.X, pos.Y }, FVector2D{ pos.X + cosf(angle) * r, pos.Y + sinf(angle) * r }, 1.0f, color);
        }
    }


void DrawFilledCircleM(AHUD *HUD, FVector2D pos, float r, FLinearColor color)
    {
        
        #define PI 3.14159265358979323846

    UCanvas *Canvas = HUD->Canvas;
        float smooth = 0.07f;

      //  double PI = 3.14159265359;
      double PIGG = 3.14159265359;
      
        int size = (int)(2.0f * PIGG / smooth) + 1;

        float angle = 0.0f;
        int i = 0;

        for (; angle < 2 * PI; angle += smooth, i++)
        {
            
            Canvas->K2_DrawLine(FVector2D(pos.X, pos.Y), FVector2D(pos.X + cosf(angle) * r, pos.Y + sinf(angle) * r ), 1.f, color);

          //  Draw_Line(FVector2D{ pos.X, pos.Y }, FVector2D{ pos.X + cosf(angle) * r, pos.Y + sinf(angle) * r }, 1.0f, color);
        }
    }
    void DrawFilledRectangle99(AHUD *HUD, FVector2D Pos, float Width, float Height, FLinearColor Color) {
        
    HUD->DrawRect(Color, Pos.X, Pos.Y, Width, Height);
    for (size_t i = 0; i <5; i++)
        HUD->  DrawRect(FLinearColor(255, 81, 75, 61), Pos.X + (i *2), Pos.Y, 1, 6);
}
    //绘制引擎圆形
void DrawCircle77(AHUD* HUD, int x, int y, int radius, int numsides, FLinearColor OutlineColor){
 UCanvas *Canvas = HUD->Canvas;
 float Step = M_PI / numsides;
 int Count = 0;
 FVector2D V[128];
 for (float a = 0; a < M_PI * 2.0; a += Step)
 {
  float X1 = radius * cos(a) + x;
  float Y1 = radius * sin(a) + y;
  float X2 = radius * cos(a + Step) + x;
  float Y2 = radius * sin(a + Step) + y;
  V[Count].X = X1;
  V[Count].Y = Y1;
  V[Count + 1].X = X2;
  V[Count + 1].Y = Y2;
  Canvas->K2_DrawLine(FVector2D({V[Count].X, V[Count].Y}), FVector2D({ X2, Y2 }), 1.f, OutlineColor);
 }
}
//绘制引擎填充圆形<不完整>
void DrawFilledCircle77(AHUD* HUD, int x, int y, int radius, FLinearColor FillColor) {
    UCanvas* Canvas = HUD->Canvas;
    float Step = 2.0f * M_PI / (float)radius;
    for (float theta = 0; theta < 2 * M_PI; theta += Step) {
        float x1 = radius * cos(theta) + x;
        float y1 = radius * sin(theta) + y;
        float x2 = radius * cos(theta + Step) + x;
        float y2 = radius * sin(theta + Step) + y;
        Canvas->K2_DrawLine(FVector2D(x1, y1), FVector2D(x2, y2), 1.0f, FillColor);
    }
}
    
void DrawArrow(AHUD *HUD, FVector2D a,FVector2D b,FVector2D c, float Thickness, FLinearColor Color) {
    
    HUD->DrawLine(a.X,a.Y, b.X,b.Y,Color,Thickness);
    HUD->DrawLine(b.X,b.Y, c.X,c.Y,Color,Thickness);
    HUD->DrawLine(c.X,c.Y, a.X,a.Y,Color,Thickness);
}


void DrawArrow7(AHUD *HUD, FVector2D xy1, FVector2D xy2, FVector2D xy3, FVector2D xy4, FVector2D xy5, FVector2D xy6, FVector2D xy7, FLinearColor Color) {
      
    
    HUD->DrawLine(xy1.X,xy1.Y, xy2.X,xy2.Y,Color,1);
    HUD->DrawLine(xy2.X,xy2.Y, xy3.X,xy3.Y,Color,1);
    HUD->DrawLine(xy3.X,xy3.Y, xy7.X,xy7.Y,Color,1);
    HUD->DrawLine(xy7.X,xy7.Y, xy6.X,xy6.Y,Color,1);
    HUD->DrawLine(xy5.X,xy5.Y, xy4.X,xy4.Y,Color,1);
    HUD->DrawLine(xy4.X,xy4.Y, xy1.X,xy1.Y,Color,1);
    HUD->DrawLine(xy6.X,xy6.Y, xy5.X,xy5.Y,Color,1);
    
    }

    void DrawLine44(AHUD *HUD, FVector2D posFrom, FVector2D posTo, float Thickness, FLinearColor Color) {
    HUD->DrawLine(posFrom.X, posFrom.Y, posTo.X, posTo.Y, Color, Thickness);
}
    void DrawArrows(AHUD * HUD,std::array < FVector2D, 39 > Loc, float thickness, FLinearColor color) {
    for (int i = 10; i < 25; i++) {
        DrawLine44(HUD,Loc.at(i), Loc.at(7), thickness, color);
    }
    for (int i = 26; i < 38; i++) {
        DrawLine44(HUD,Loc.at(i), Loc.at(7), thickness + 1.5, color);
        DrawLine44(HUD,Loc.at(i), Loc.at(8), thickness+ 1.5f, color);
        DrawLine44(HUD,Loc.at(i), Loc.at(9), thickness + 1.5f, color);
    }
    DrawLine44(HUD,Loc.at(0), Loc.at(1), thickness * 1.f, COLOR_BLACK);
    DrawLine44(HUD,Loc.at(1), Loc.at(2), thickness * 1.f, COLOR_BLACK);
    DrawLine44(HUD,Loc.at(2), Loc.at(6), thickness * 1.f, COLOR_BLACK);
    DrawLine44(HUD,Loc.at(6), Loc.at(5), thickness * 1.f, COLOR_BLACK);
    DrawLine44(HUD,Loc.at(5), Loc.at(4), thickness * 1.f, COLOR_BLACK);
    DrawLine44(HUD,Loc.at(4), Loc.at(3), thickness * 1.f, COLOR_BLACK);
    DrawLine44(HUD,Loc.at(3), Loc.at(0), thickness * 1.f, COLOR_BLACK);
}
    
FVector RotateCorner(FVector origin, FVector corner, float theta)
{
    float x = corner.X - origin.X;
    float y = corner.Y - origin.Y;
    return {
        origin.X + (x * cos(theta) - y * sin(theta)),
        origin.Y + (x * sin(theta) + y * cos(theta)),
        corner.Z
    };
}
ASTExtraPlayerController *g_PlayerController;
float EspBoxThik = 1.5f;
void DrawBox3D(AHUD *HUD, AActor* actor, FLinearColor Color, FVector origin, FVector extent) {
    auto MathLibrary = (UKismetMathLibrary *) UKismetMathLibrary::StaticClass();
    auto GameplayStatics = (UGameplayStatics *) UGameplayStatics::StaticClass();
    FRotator rotation = actor->K2_GetActorRotation();
    float yaw = MathLibrary->DegreesToRadians((int)(rotation.Yaw + 450.0f) % 360);
    FVector2D ts1, ts2, ts3, ts4, bs1, bs2, bs3, bs4;
    FVector t1, t2, t3, t4, b1, b2, b3, b4;
    t1 = t2 = t3 = t4 = b1 = b2 = b3 = b4 = origin;
    t1.X -= extent.X;
    t1.Y -= extent.Y;
    t1.Z -= extent.Z;
    t2.X += extent.X;
    t2.Y -= extent.Y;
    t2.Z -= extent.Z;
    t3.X += extent.X;
    t3.Y += extent.Y;
    t3.Z -= extent.Z;
    t4.X -= extent.X;
    t4.Y += extent.Y;
    t4.Z -= extent.Z;
    t1 = RotateCorner(origin, t1, yaw);
    t2 = RotateCorner(origin, t2, yaw);
    t3 = RotateCorner(origin, t3, yaw);
    t4 = RotateCorner(origin, t4, yaw);
    b1.X -= extent.X;
    b1.Y -= extent.Y;
    b1.Z += extent.Z;
    b2.X += extent.X;
    b2.Y -= extent.Y;
    b2.Z += extent.Z;
    b3.X += extent.X;
    b3.Y += extent.Y;
    b3.Z += extent.Z;
    b4.X -= extent.X;
    b4.Y += extent.Y;
    b4.Z += extent.Z;
    b1 = RotateCorner(origin, b1, yaw);
    b2 = RotateCorner(origin, b2, yaw);
    b3 = RotateCorner(origin, b3, yaw);
    b4 = RotateCorner(origin, b4, yaw);
    if (GameplayStatics->ProjectWorldToScreen(g_PlayerController, b1, false, &bs1) && GameplayStatics->ProjectWorldToScreen(g_PlayerController, b2, false, &bs2)&& GameplayStatics->ProjectWorldToScreen(g_PlayerController, b3, false, &bs3)&& GameplayStatics->ProjectWorldToScreen(g_PlayerController, b4, false, &bs4)&& GameplayStatics->ProjectWorldToScreen(g_PlayerController, t1, false, &ts1)&& GameplayStatics->ProjectWorldToScreen(g_PlayerController, t2, false, &ts2)&& GameplayStatics->ProjectWorldToScreen(g_PlayerController, t3, false, &ts3)&& GameplayStatics->ProjectWorldToScreen(g_PlayerController, t4, false, &ts4)) {
        DrawLine(HUD, ts1, ts2, EspBoxThik, Color);
        DrawLine(HUD, ts2, ts3, EspBoxThik, Color);
        DrawLine(HUD, ts3, ts4, EspBoxThik, Color);
        DrawLine(HUD, ts4, ts1, EspBoxThik, Color);
        DrawLine(HUD, bs1, bs2, EspBoxThik, Color);
        DrawLine(HUD, bs2, bs3, EspBoxThik, Color);
        DrawLine(HUD, bs3, bs4, EspBoxThik, Color);
        DrawLine(HUD, bs4, bs1, EspBoxThik, Color);
        DrawLine(HUD, ts1, bs1, EspBoxThik, Color);
        DrawLine(HUD, ts2, bs2, EspBoxThik, Color);
        DrawLine(HUD, ts3, bs3, EspBoxThik, Color);
        DrawLine(HUD, ts4, bs4, EspBoxThik, Color);
    }
}
 /*
void DrawCircle33(AHUD *HUD, int x, int y, int radius, int numsides, float Thickness, FLinearColor OutlineColor)
{
    UCanvas *DebugCanvas = HUD->DebugCanvas;
    
#define M_PI                   3.14159265358979323846f

    
    float Step = M_PI * 2.0 / numsides;
    int Count = 0;
    FVector2D V[128];
    for (float a = 0; a < M_PI * 2.0; a += Step)
    {
        float X1 = radius * cos(a) + x;
        float Y1 = radius * sin(a) + y;
        float X2 = radius * cos(a + Step) + x;
        float Y2 = radius * sin(a + Step) + y;
        V[Count].X = X1;
        V[Count].Y = Y1;
        V[Count + 1].X = X2;
        V[Count + 1].Y = Y2;
        
        
        
        
        DebugCanvas->K2_DrawLine(FVector2D({V[Count].X, V[Count].Y}), FVector2D({X2, Y2}), Thickness, OutlineColor);
    }
}

*/

void DrawCircle33(AHUD *HUD, int x, int y, int radius, float Thickness, FLinearColor OutlineColor)
{
    UCanvas *Canvas = HUD->Canvas;
    
#define M_PI                   3.14159265358979323846f

    
    float Step = M_PI * 2.0 / 360;
    int Count = 0;
    FVector2D V[128];
    for (float a = 0; a < M_PI * 2.0; a += Step)
    {
        float X1 = radius * cos(a) + x;
        float Y1 = radius * sin(a) + y;
        float X2 = radius * cos(a + Step) + x;
        float Y2 = radius * sin(a + Step) + y;
        V[Count].X = X1;
        V[Count].Y = Y1;
        V[Count + 1].X = X2;
        V[Count + 1].Y = Y2;
        
       
        
        Canvas->K2_DrawLine(FVector2D({V[Count].X, V[Count].Y}), FVector2D({X2, Y2}), Thickness, OutlineColor);
    }
}

void Box3D(AHUD *HUD, FVector origin, FVector extends, FLinearColor Color, float LineSize) {
    auto GameplayStatics = (UGameplayStatics *) UGameplayStatics::StaticClass();
    origin.X -= extends.X / 2.f;
    origin.Y -= extends.Y / 2.f;
    origin.Z -= extends.Z / 2.f;
    
    
 FVector one = origin;
 FVector two = origin; two.X += extends.X;
 FVector tree = origin; tree.X += extends.X; tree.Y += extends.Y;
 FVector four = origin; four.Y += extends.Y;

 FVector five = one; five.Z += extends.Z;
 FVector six = two; six.Z += extends.Z;
 FVector seven = tree; seven.Z += extends.Z;
 FVector eight = four; eight.Z += extends.Z;

    FVector2D s1, s2, s3, s4, s5, s6, s7, s8;
    /*
    if (W2S(one, &s1) && W2S(two, &s2) && W2S(tree, &s3) && W2S2(four, &s4) &&
    W2S2(five, &s5) && W2S2(six, &s6) && W2S2(seven, &s7) && W2S2(eight, &s8))
    {
        */
    if (GameplayStatics->ProjectWorldToScreen(g_LocalController, one, false, &s1) && GameplayStatics->ProjectWorldToScreen(g_LocalController, two, false, &s2)&& GameplayStatics->ProjectWorldToScreen(g_LocalController, tree, false, &s3)&& GameplayStatics->ProjectWorldToScreen(g_LocalController, four, false, &s4)&& GameplayStatics->ProjectWorldToScreen(g_LocalController, five, false, &s5)&& GameplayStatics->ProjectWorldToScreen(g_LocalController, six, false, &s6)&& GameplayStatics->ProjectWorldToScreen(g_LocalController, seven, false, &s7)&& GameplayStatics->ProjectWorldToScreen(g_LocalController, eight, false, &s8)) {

 HUD->DrawLine(s1.X,s1.Y, s2.X,s2.Y,Color, LineSize);
 HUD->DrawLine(s2.X,s2.Y, s3.X,s3.Y,Color, LineSize);
 HUD->DrawLine(s3.X,s3.Y, s4.X,s4.Y,Color, LineSize);
 HUD->DrawLine(s4.X,s4.Y, s1.X,s1.Y,Color, LineSize);

 HUD->DrawLine(s5.X,s5.Y, s6.X,s6.Y,Color, LineSize);
 HUD->DrawLine(s6.X,s6.Y, s7.X,s7.Y,Color, LineSize);
 HUD->DrawLine(s7.X,s7.Y, s8.X,s8.Y,Color, LineSize);
 HUD->DrawLine(s8.X,s8.Y, s5.X,s5.Y,Color, LineSize);

 HUD->DrawLine(s1.X,s1.Y, s5.X,s5.Y,Color, LineSize);
 HUD->DrawLine(s2.X,s2.Y, s6.X,s6.Y,Color, LineSize);
 HUD->DrawLine(s3.X,s3.Y, s7.X,s7.Y,Color, LineSize);
 HUD->DrawLine(s4.X,s4.Y, s8.X,s8.Y,Color, LineSize);
}
}



void LineE(AHUD *HUD, FVector2D posFrom, FVector2D posTo, float Thickness, FLinearColor Color) {
    HUD->DrawLine(posFrom.X, posFrom.Y, posTo.X, posTo.Y, Color, Thickness);
}

void DrawBox3D4(AHUD *HUD, AActor* actor, FLinearColor Color, FVector origin, FVector extent) {
    auto MathLibrary = (UKismetMathLibrary *) UKismetMathLibrary::StaticClass();
    auto GameplayStatics = (UGameplayStatics *) UGameplayStatics::StaticClass();
    FRotator rotation = actor->K2_GetActorRotation();
    float yaw = MathLibrary->DegreesToRadians((int)(rotation.Yaw + 450.0f) % 360);
    FVector2D ts1, ts2, ts3, ts4, bs1, bs2, bs3, bs4;
    FVector t1, t2, t3, t4, b1, b2, b3, b4;
    t1 = t2 = t3 = t4 = b1 = b2 = b3 = b4 = origin;
    t1.X -= extent.X;
    t1.Y -= extent.Y;
    t1.Z -= extent.Z;
    t2.X += extent.X;
    t2.Y -= extent.Y;
    t2.Z -= extent.Z;
    t3.X += extent.X;
    t3.Y += extent.Y;
    t3.Z -= extent.Z;
    t4.X -= extent.X;
    t4.Y += extent.Y;
    t4.Z -= extent.Z;
    t1 = RotateCorner(origin, t1, yaw);
    t2 = RotateCorner(origin, t2, yaw);
    t3 = RotateCorner(origin, t3, yaw);
    t4 = RotateCorner(origin, t4, yaw);
    b1.X -= extent.X;
    b1.Y -= extent.Y;
    b1.Z += extent.Z;
    b2.X += extent.X;
    b2.Y -= extent.Y;
    b2.Z += extent.Z;
    b3.X += extent.X;
    b3.Y += extent.Y;
    b3.Z += extent.Z;
    b4.X -= extent.X;
    b4.Y += extent.Y;
    b4.Z += extent.Z;
    b1 = RotateCorner(origin, b1, yaw);
    b2 = RotateCorner(origin, b2, yaw);
    b3 = RotateCorner(origin, b3, yaw);
    b4 = RotateCorner(origin, b4, yaw);
    if (GameplayStatics->ProjectWorldToScreen(g_LocalController, b1, false, &bs1) && GameplayStatics->ProjectWorldToScreen(g_LocalController, b2, false, &bs2)&& GameplayStatics->ProjectWorldToScreen(g_LocalController, b3, false, &bs3)&& GameplayStatics->ProjectWorldToScreen(g_LocalController, b4, false, &bs4)&& GameplayStatics->ProjectWorldToScreen(g_LocalController, t1, false, &ts1)&& GameplayStatics->ProjectWorldToScreen(g_LocalController, t2, false, &ts2)&& GameplayStatics->ProjectWorldToScreen(g_LocalController, t3, false, &ts3)&& GameplayStatics->ProjectWorldToScreen(g_LocalController, t4, false, &ts4)) {
        LineE(HUD, ts1, ts2, 1.5f, Color);
        LineE(HUD, ts2, ts3, 1.5f, Color);
        LineE(HUD, ts3, ts4, 1.5f, Color);
        LineE(HUD, ts4, ts1, 1.5f, Color);
        LineE(HUD, bs1, bs2, 1.5f, Color);
        LineE(HUD, bs2, bs3, 1.5f, Color);
        LineE(HUD, bs3, bs4, 1.5f, Color);
        LineE(HUD, bs4, bs1, 1.5f, Color);
        LineE(HUD, ts1, bs1, 1.5f, Color);
        LineE(HUD, ts2, bs2, 1.5f, Color);
        LineE(HUD, ts3, bs3, 1.5f, Color);
        LineE(HUD, ts4, bs4, 1.5f, Color);
    }
}
void DrawCircle335(AHUD *HUD, int x, int y, int radius, int numsides, float Thickness, FLinearColor OutlineColor)
{
    UCanvas *DebugCanvas = HUD->DebugCanvas;
    
#define M_PI                   3.14159265358979323846f

    
    float Step = M_PI * 2.0 / numsides;
    int Count = 0;
    FVector2D V[128];
    for (float a = 0; a < M_PI * 2.0; a += Step)
    {
        float X1 = radius * cos(a) + x;
        float Y1 = radius * sin(a) + y;
        float X2 = radius * cos(a + Step) + x;
        float Y2 = radius * sin(a + Step) + y;
        V[Count].X = X1;
        V[Count].Y = Y1;
        V[Count + 1].X = X2;
        V[Count + 1].Y = Y2;
        
        
        
        DebugCanvas->K2_DrawLine(FVector2D({V[Count].X, V[Count].Y}), FVector2D({X2, Y2}), Thickness, OutlineColor);
    }
}
void Box4Line(AHUD *HUD, int x, int y, int w, int h, FLinearColor Color) {
    
    int iw = w / 4;
    int ih = h / 4;
    // top
    HUD->DrawLine(x, y, x + iw, y ,Color,1.5);
    HUD->DrawLine(x + w - iw, y, x + w, y,Color,1.5);
    HUD->DrawLine(x, y, x, y + ih,Color,1.5);
    HUD->DrawLine(x + w - 1, y, x + w - 1, y + ih,Color,1.5);
    
    // bottom
    HUD->DrawLine(x, y + h, x + iw, y + h,Color,1.5);
    HUD->DrawLine(x + w - iw, y + h, x + w, y + h,Color,1.5);
    HUD->DrawLine(x, y + h - ih, x, y + h,Color,1.5);
    HUD->DrawLine(x + w - 1, y + h - ih, x + w - 1, y + h,Color,1.5);
    
    
    }
void DrawCircle(AHUD *HUD, int x, int y, int radius, int numsides, FLinearColor OutlineColor) {
    UCanvas *Canvas = HUD->Canvas;
    float Step = M_PI * 2.0 / numsides;
    int Count = 0;
    FVector2D V[128];
    for (float a = 0; a < M_PI * 2.0; a += Step)
    {
        float X1 = radius * cos(a) + x;
        float Y1 = radius * sin(a) + y;
        float X2 = radius * cos(a + Step) + x;
        float Y2 = radius * sin(a + Step) + y;
        V[Count].X = X1;
        V[Count].Y = Y1;
        V[Count + 1].X = X2;
        V[Count + 1].Y = Y2;
        Canvas->K2_DrawLine(FVector2D({V[Count].X, V[Count].Y}), FVector2D({X2, Y2}), 1.f, OutlineColor);
    }
}
void RotateTriangle55(std::array < FVector2D, 39 > &points, float rotation)
{
   const auto points_center = (points.at(0) + points.at(1) + points.at(2) + points.at(3) + points.at(4) + points.at(5) + points.at(6)
                                + points.at(7) + points.at(8) + points.at(9) + points.at(10) + points.at(11) + points.at(12) + points.at(13)
                                + points.at(14) + points.at(15) + points.at(16) + points.at(17) + points.at(18) + points.at(19) + points.at(20)
                                + points.at(21) + points.at(22) + points.at(23) + points.at(24) + points.at(25) + points.at(26) + points.at(27)
                                + points.at(28) + points.at(29) + points.at(30) + points.at(31) + points.at(32) + points.at(33) + points.at(34)
                                + points.at(35) + points.at(36) + points.at(37) + points.at(38)) / 39;
    for (auto & point:points) {
        point = point - points_center;
        const auto temp_x = point.X;
        const auto temp_y = point.Y;
        const auto theta = DEG2RAD(rotation);
        const auto c = cosf(theta);
        const auto s = sinf(theta);
        point.X = temp_x * c - temp_y * s;
        point.Y = temp_x * s + temp_y * c;
        point = point + points_center;
    }
}
void VectorAnglesRadar(FVector& forward, FVector& angles)
{
    if (forward.X == 0.f && forward.Y == 0.f)
    {
        angles.X = forward.Z > 0.f ? -90.f : 90.f;
        angles.Y = 0.f;
    }
    else
    {
        angles.X = RAD2DEG(atan2(-forward.Z, forward.Size()));
        angles.Y = RAD2DEG(atan2(forward.Y, forward.X));
    }
    angles.Z = 0.f;
}
/*
void FixTriangle(float& XPos, float& YPos, int screenDist){
    //
    // —————————Triangle X Pos—————————————
    if(XPos > (screenWidth - 16)) {
        XPos = screenWidth;
        XPos -= screenDist;
    }
    // ——————————————————————
    if(XPos < 16) {
        XPos = 16;
        XPos += screenDist;
    }
    // ————————— Triangle Y Pos —————————————
    if(YPos > (screenHeight - 16)) {
        YPos = screenHeight;
        YPos -= screenDist;
    }
    if(YPos < 16) {
        YPos = 16;
        YPos += screenDist;
    }
}
*/

void FixTriangle(float& XPos, float& YPos, int screenDist){
// Made By @P8MMM (TELEGRAM)
// —————————Triangle X Pos—————————————
if(XPos > (screenWidth - 16)) {
XPos = screenWidth;
XPos -= screenDist;
}
// ——————————————————————
if(XPos < 16) {
XPos = 16;
XPos += screenDist;
}
// ————————— Triangle Y Pos —————————————
if(YPos > (screenHeight - 16)) {
YPos = screenHeight;
YPos -= screenDist;
}
if(YPos < 16) {
YPos = 16;
YPos += screenDist;
}
}


FVector2D WorldToRadar(float Yaw, FVector Origin, FVector LocalOrigin, float PosX, float PosY,
                       FVector Size, bool & outbuff)
{
    bool flag = false;
    double num = (double)Yaw;
    double num2 = num * 0.017453292519943295;
    float num3 = (float)std::cos(num2);
    float num4 = (float)std::sin(num2);
    float num5 = Origin.X - LocalOrigin.X;
    float num6 = Origin.Y - LocalOrigin.Y;
    FVector2D vector;
    vector.X = (num6 * num3 - num5 * num4) / 150.f;
    vector.Y = (num5 * num3 + num6 * num4) / 150.f;
    FVector2D vector2;
    vector2.X = vector.X + PosX + Size.X / 2.f;
    vector2.Y = -vector.Y + PosY + Size.Y / 2.f;
    bool flag2 = vector2.X > PosX + Size.X;
    if (flag2)
    {
        vector2.X = PosX + Size.X;
    }
    else
    {
        bool flag3 = vector2.X < PosX;
        if (flag3)
        {
            vector2.X = PosX;
        }
    }
    bool flag4 = vector2.Y > PosY + Size.Y;
    if (flag4)
    {
        vector2.Y = PosY + Size.Y;
    }
    else
    {
        bool flag5 = vector2.Y < PosY;
        if (flag5)
        {
            vector2.Y = PosY;
        }
    }
    bool flag6 = vector2.Y == PosY || vector2.X == PosX;
    if (flag6)
    {
        flag = true;
    }
    outbuff = flag;
    return vector2;
}
FLinearColor Black = { 0.000000000f, 0.000000000f, 0.000000000f, 1.000000000f };
void DrawTextIos(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, bool isCenter = true) {
    UCanvas *DebugCanvas = HUD->DebugCanvas;
    DebugCanvas->K2_DrawText(tslFont, Text, Pos, Color, 1, {}, {}, isCenter, isCenter, true, Black);
    
}

void DrawOutlinedTextIos(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, FLinearColor OutlineColor, bool isCenter = true) {
    
    UCanvas *Canvas = HUD->Canvas;
    Canvas->K2_DrawText(tslFont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, true, OutlineColor);
    
}

void DrawTextcan(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, FLinearColor OutlineColor, bool isCenter = true) {
    UCanvas *Canvas = HUD->Canvas;
    Canvas->K2_DrawText(itemfont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, true, OutlineColor);
}


void DrawTextcanV2(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, FLinearColor OutlineColor, bool isCenter = true) {
    UCanvas *Canvas = HUD->Canvas;
    Canvas->K2_DrawText(itemfont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, true, OutlineColor);
}

void DrawTextcanV3(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, FLinearColor OutlineColor, bool isCenter = true) {
    UCanvas *DebugCanvas = HUD->DebugCanvas;
    DebugCanvas->K2_DrawText(itemfont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, true, OutlineColor);
}
void DrawOutlineditem( UCanvas *Canvas, FString Text, FVector2D Pos, FLinearColor Color, FLinearColor OutlineColor, bool isCenter = true) {
    
    Canvas->K2_DrawText(tslFont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, true, OutlineColor);
    
}

void DrawOutlinedText2(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, FLinearColor OutlineColor, bool isCenter = false) {
    UCanvas *DebugCanvas = HUD->DebugCanvas;
    DebugCanvas->K2_DrawText(tslFont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, true, OutlineColor);
}


void DrawOutlinedText77(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, bool isCenter = false) {
    UCanvas *Canvas = HUD->Canvas;
    Canvas->K2_DrawText(robotoTinyFont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, false, {});
}

void DrawText2(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, bool isCenter = false) {
    UCanvas *DebugCanvas = HUD->DebugCanvas;
    DebugCanvas->K2_DrawText(tslFont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, false, {});
}




void DrawOutlinedTextNRG(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, bool isCenter = false) {
    UCanvas *Canvas = HUD->Canvas;
    Canvas->K2_DrawText(tslFont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, true, {});
}

void DrawOutlinedText(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, FLinearColor OutlineColor, bool isCenter = false) {
    UCanvas *Canvas = HUD->Canvas;
    Canvas->K2_DrawText(tslFont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, true, OutlineColor);
}

void DrawOutlinedTexttt(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, FLinearColor OutlineColor, bool isCenter = false) {
    UCanvas *Canvas = HUD->Canvas;
    Canvas->K2_DrawText(itemfont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, true, OutlineColor);
}
void DrawOutlinedText888(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, FLinearColor OutlineColor, bool isCenter = false) {
    UCanvas *Canvas = HUD->Canvas;
    Canvas->K2_DrawText(tslFontS, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, true, OutlineColor);
}


void DrawText666(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, bool isCenter = false) {
    UCanvas *DebugCanvas = HUD->DebugCanvas;
    DebugCanvas->K2_DrawText(tslFont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, false, {});
}


void DrawSmallText(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, bool isCenter = false) {
    UCanvas *Canvas = HUD->Canvas;
    Canvas->K2_DrawText(robotoTinyFont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, false, {});
}

void DrawText(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, bool isCenter = false) {
    UCanvas *Canvas = HUD->Canvas;
    Canvas->K2_DrawText(tslFont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, false, {});
}

void DrawSmallOutlinedText(AHUD *HUD, FString Text, FVector2D Pos, FLinearColor Color, FLinearColor OutlineColor, bool isCenter = false) {
    UCanvas *Canvas = HUD->Canvas;
    Canvas->K2_DrawText(robotoTinyFont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, true, OutlineColor);
}


void DrawLine44(  UCanvas *Canvas, FVector2D posFrom, FVector2D posTo, float Thickness, FLinearColor Color) {
    
    
    Canvas->K2_DrawLine(posFrom, posTo, Thickness, Color);
    
}

void *LoadFont(void *)
{
    while (!tslFont || !robotoTinyFont || !tslFontS || !itemfont)
    {
        tslFont = UObject::FindObject<UFont>("Font Roboto.Roboto"); // Font Roboto.Roboto
        robotoTinyFont = UObject::FindObject<UFont>("Font RobotoDistanceField.RobotoDistanceField");
        tslFontS = UObject::FindObject<UFont>("Font TSLFont.TSLFont"); // Font Roboto.Roboto
        itemfont = UObject::FindObject<UFont>("Font TSLFont.TSLFont");
        sleep(1);
    }
    return 0;
}



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
    
    int helmetlv1 = 502001;
    int helmetlv2 = 502002;
    int helmetlv3 = 502003;
    
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
  if (m4SkinHackHudSdk == 1) {
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
    new_Skin.M416_verical = 1010040481;
    new_Skin.M416_thumb = 1010040478;
    new_Skin.M416_angle = 1010040477;
    new_Skin.M416_lightgrip = 1010040482;
    new_Skin.M416_pink = 1010040483;
    new_Skin.M416_lazer = 1010040484;
  }
  if (m4SkinHackHudSdk == 2) {
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
  if (m4SkinHackHudSdk == 3) {
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
  if (m4SkinHackHudSdk == 4) {
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
  if (m4SkinHackHudSdk == 5) {
    new_Skin.M416_1 = 1101004098;
    new_Skin.M416_2 = 1010040981;
    new_Skin.M416_3 = 1010040982;
    new_Skin.M416_4 = 1010040983;
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
  if (m4SkinHackHudSdk == 6) {
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
    new_Skin.M416_x4 = 1010041124;
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
  if (m4SkinHackHudSdk == 7) {
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
  if (m4SkinHackHudSdk == 8) {
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
  if (m4SkinHackHudSdk == 9) {
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
  if (m4SkinHackHudSdk == 10) {
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
  
  
      if (amrSkinHackHudSdk == 0)
    new_Skin.AMR = 103012;
  if (amrSkinHackHudSdk == 1)
    new_Skin.AMR = 1103012010;//ADD
    
      if (mk14SkinHackHudSdk == 0)
    new_Skin.MK14 = 103007;
  if (mk14SkinHackHudSdk == 1)
    new_Skin.MK14 = 1103007020;//ADD
      if (mk14SkinHackHudSdk == 2)
    new_Skin.MK14 = 1103007028;//ADD
    

  if (MG3SkinHackHudSdk == 0)
    new_Skin.MG3 = 105010;
  if (MG3SkinHackHudSdk == 1)
    new_Skin.MG3 = 1105010008;//ADD
    
    
    
    
    
//LV-1
if (bagSkinHackHudSdk == 0)
new_Skin.baglv1 = 501001; //LV 1
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
new_Skin.baglv1 = 1501001550;//Frosty Snowglobe Backpack (Lv. 1)
if (bagSkinHackHudSdk == 9)
new_Skin.baglv1 = 1501001552; //Ebil Bunny Backpack (Lv. 1)
if (bagSkinHackHudSdk == 10)
new_Skin.baglv1 = 1501001061; //Godzilla Backpack (Lv. 1)
    
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

//LV-3
if (bagSkinHackHudSdk == 0)
//new_Skin.baglv3 = 501003; //LV 3
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
//new_Skin.helmetlv3 = 502003; //lv 3
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
    new_Skin.Moto = 1901047;
  if (MotoSkinHackSdk == 5)
    new_Skin.Moto = 1901085;
  if (MotoSkinHackSdk == 6)
    new_Skin.Moto = 1901076;
  if (MotoSkinHackSdk == 7)
    new_Skin.Moto = 1901027;
  if (MotoSkinHackSdk == 8)
    new_Skin.Moto = 1901018;
  if (MotoSkinHackSdk == 9)
    new_Skin.Moto = 1901085;
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
    
                  if (DaciaSkinHackSdk == 1) {
                    new_Skin.Dacia = 1903075; //Koenigsegg Gemera (Rainbow)
                    } else if (DaciaSkinHackSdk == 2) {
                    new_Skin.Dacia = 1903080; //Koenigsegg Gemera (Silver Grey)
                    } else if (DaciaSkinHackSdk == 3) {
                    new_Skin.Dacia = 1903076; //Koenigsegg Gemera (Drawn)
                    } else if (DaciaSkinHackSdk == 4) {
                    new_Skin.Dacia = 1903073; //Tesla Roadster (Digital Water) ( DACIA )
                    } else if (DaciaSkinHackSdk == 5) {
                    new_Skin.Dacia = 1903074; //Koenigsegg Gemera (Silver Gray) ( DACIA )
                    } else if (DaciaSkinHackSdk == 6) {
                    new_Skin.Dacia = 1903072; //Koenigsegg Gemera (Rainbow) ( DACIA )
                    } else if (DaciaSkinHackSdk == 7) {
                    new_Skin.Dacia = 1903189; //Lamborghini Estoque Metal Grey ( DACIA )
                    } else if (DaciaSkinHackSdk == 8) {
                    new_Skin.Dacia = 1903071; //Tesla Roadster (Diamond) ( DACIA )
                    } else if (DaciaSkinHackSdk == 9) {
                    new_Skin.Dacia = 1903190; //Lamborghini Estoque Metal Grey
                    } else if (DaciaSkinHackSdk == 10) {
                    new_Skin.Dacia = 1903079; //Lamborghini Estoque Oro
                    } else if (DaciaSkinHackSdk == 11) {
                    new_Skin.Dacia = 1903193; //Lamborghini Estoque Oro
                    } else if (DaciaSkinHackSdk == 12) {
                    new_Skin.Dacia = 1903200; //
                    } else if (DaciaSkinHackSdk == 13) {
                    new_Skin.Dacia = 1903201; //
                    } else if (DaciaSkinHackSdk == 14) {
                    new_Skin.Dacia = 1903001; //
                    } else if (DaciaSkinHackSdk == 15) {
                    new_Skin.Dacia = 1903014; //
                    } else if (DaciaSkinHackSdk == 16) {
                    new_Skin.Dacia = 1903017; //
                    } else if (DaciaSkinHackSdk == 17) {
                    new_Skin.Dacia = 1903035; //
                    } else if (DaciaSkinHackSdk == 18) {
                    new_Skin.Dacia = 1903087; //
                    } else if (DaciaSkinHackSdk == 19) {
                    new_Skin.Dacia = 1903088; //
                    } else if (DaciaSkinHackSdk == 20) {
                    new_Skin.Dacia = 1903089; //
                    } else if (DaciaSkinHackSdk == 21) {
                    new_Skin.Dacia = 1903090; //
                    } else if (DaciaSkinHackSdk == 22) {
                    new_Skin.Dacia = 1903191; //
                    } else if (DaciaSkinHackSdk == 23) {
                    new_Skin.Dacia = 1903192; //
                    } else if (DaciaSkinHackSdk == 24) {
                    new_Skin.Dacia = 1903197; //
                    } 
  
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
  
    //Coupe RB
    //CoupeRPSkinHackSdk
 if (CoupeRPSkinHackSdk == 1) {
                    new_Skin.CoupeRP = 1961020; //Lamborghini Aventador (Green) - CoupleRB
                    } else if (CoupeRPSkinHackSdk == 2) {
                    new_Skin.CoupeRP = 1961033; //Warp Green - CoupleRB
                    } else if (CoupeRPSkinHackSdk == 3) {
                    new_Skin.CoupeRP = 1961032; //Koenigsegg One:1 Phoenix - CoupleRB
                    } else if (CoupeRPSkinHackSdk == 4) {
                    new_Skin.CoupeRP = 1961039; //Maserati MC20 Rosso Vincente - CoupleRB
                    } else if (CoupeRPSkinHackSdk == 5) {
                    new_Skin.CoupeRP = 1961046; //Bugatti La Voiture Noire (Warrior)
                    } else if (CoupeRPSkinHackSdk == 6) {
                    new_Skin.CoupeRP = 1961048; //Aston Martin Valkyrie (Luminous Diamond)
                    } else if (CoupeRPSkinHackSdk == 7) {
                    new_Skin.CoupeRP = 1961029; //Koenigsegg One:1 Gilt
                    } else if (CoupeRPSkinHackSdk == 8) {
                    new_Skin.CoupeRP = 1961025; //Lamborghini Centenario Carbon Fiber
                    } else if (CoupeRPSkinHackSdk == 9) {
                    new_Skin.CoupeRP = 1961021; //Lamborghini Centenario Carbon Fiber
                    } else if (CoupeRPSkinHackSdk == 10) {
                    new_Skin.CoupeRP = 1961017; //Koenigsegg Jesko (Rainbow)
                    } else if (CoupeRPSkinHackSdk == 11) {
                    new_Skin.CoupeRP = 1961042; //Koenigsegg Jesko (Rainbow)
                    } else if (CoupeRPSkinHackSdk == 12) {
                    new_Skin.CoupeRP = 1961051; //
                    } else if (CoupeRPSkinHackSdk == 13) {
                    new_Skin.CoupeRP = 1961052; //
                    } else if (CoupeRPSkinHackSdk == 14) {
                    new_Skin.CoupeRP = 1961053; //
                    } else if (CoupeRPSkinHackSdk == 15) {
                    new_Skin.CoupeRP = 1961054; //
                    } else if (CoupeRPSkinHackSdk == 16) {
                    new_Skin.CoupeRP = 1961055; //
                    } else if (CoupeRPSkinHackSdk == 17) {
                    new_Skin.CoupeRP = 1961056; //
                    } else if (CoupeRPSkinHackSdk == 18) {
                    new_Skin.CoupeRP = 1961057; //
                    } else if (CoupeRPSkinHackSdk == 19) {
                    new_Skin.CoupeRP = 1961016; //
                    } else if (CoupeRPSkinHackSdk == 20) {
                    new_Skin.CoupeRP = 1961007; //
                    } else if (CoupeRPSkinHackSdk == 21) {
                    new_Skin.CoupeRP = 1961010; //
                    } else if (CoupeRPSkinHackSdk == 22) {
                    new_Skin.CoupeRP = 1961012; //
                    } else if (CoupeRPSkinHackSdk == 23) {
                    new_Skin.CoupeRP = 1961013; //
                    } else if (CoupeRPSkinHackSdk == 24) {
                    new_Skin.CoupeRP = 1961014; //
                    } else if (CoupeRPSkinHackSdk == 25) {
                    new_Skin.CoupeRP = 1961015; //
                    } else if (CoupeRPSkinHackSdk == 26) {
                    new_Skin.CoupeRP = 1961047; //
                    } else if (CoupeRPSkinHackSdk == 27) {
                    new_Skin.CoupeRP = 1961137; //
                    } else if (CoupeRPSkinHackSdk == 28) {
                    new_Skin.CoupeRP = 1961138; //
                    } else if (CoupeRPSkinHackSdk == 29) {
                    new_Skin.CoupeRP = 1961139; //
                    } else if (CoupeRPSkinHackSdk == 30) {
                    new_Skin.CoupeRP = 1961043; //
                    } else if (CoupeRPSkinHackSdk == 31) {
                    new_Skin.CoupeRP = 1961044; //
                    } else if (CoupeRPSkinHackSdk == 32) {
                    new_Skin.CoupeRP = 1961045; //
                    } else if (CoupeRPSkinHackSdk == 33) {
                    new_Skin.CoupeRP = 1961046; //
                    } else if (CoupeRPSkinHackSdk == 34) {
                    new_Skin.CoupeRP = 1961050; //
                    } else if (CoupeRPSkinHackSdk == 35) {
                    new_Skin.CoupeRP = 1961001; //
                    } else if (CoupeRPSkinHackSdk == 36) {
                    new_Skin.CoupeRP = 1961024; //
                    } else if (CoupeRPSkinHackSdk == 37) {
                    new_Skin.CoupeRP = 1961034; //
                    } else if (CoupeRPSkinHackSdk == 38) {
                    new_Skin.CoupeRP = 1961018; //
                    } else if (CoupeRPSkinHackSdk == 39) {
                    new_Skin.CoupeRP = 1961049; //
                    } else if (CoupeRPSkinHackSdk == 40) {
                    new_Skin.CoupeRP = 1961030; //
                    } else if (CoupeRPSkinHackSdk == 41) {
                    new_Skin.CoupeRP = 1961031; //
                    } else if (CoupeRPSkinHackSdk == 42) {
                    new_Skin.CoupeRP = 1961035; //
                    } else if (CoupeRPSkinHackSdk == 43) {
                    new_Skin.CoupeRP = 1961036; //
                    } else if (CoupeRPSkinHackSdk == 44) {
                    new_Skin.CoupeRP = 1961037; //
                    } else if (CoupeRPSkinHackSdk == 45) {
                    new_Skin.CoupeRP = 1961038; //
                    } else if (CoupeRPSkinHackSdk == 46) {
                    new_Skin.CoupeRP = 1961040; //
                    } else if (CoupeRPSkinHackSdk == 47) {
                    new_Skin.CoupeRP = 1961041; //
                    } 
                    
    /*
    
    1903200  -  Bentley Flying Spur Mulliner (Nebula)  
1903201  -  Bentley Flying Spur Mulliner (Damson over Silver Storm)  
1908094  -  Bentley Bentayga Azure (Galaxy Glitter)  
1908095  -  Bentley Bentayga Azure (Magnetic)  
1915008  -  Bentley Continental GTC Mulliner (Holocrystal)  
1915009  -  Bentley Continental GTC Mulliner (Tanzanite Purple)  
1961137  -  Bentley Batur (Holoprism)  
1961138  -  Bentley Batur (Solar Pulse)  
1961139  -  Bentley Batur (Bonneville Pearlescent Silver)

3.1 Bently Car Skin I'd

Join For More : (https://t.me/+-ucVzdEc4GYyNDM1)
    */
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//UAZ
  //UAZSkinHackSdk

                   if (UAZSkinHackSdk == 1) {
                    new_Skin.UAZ = 1908070; //Robust Universe
                    } else if (UAZSkinHackSdk == 2) {
                    new_Skin.UAZ = 1908077; //Maserati Levante Neon Urbano
                    } else if (UAZSkinHackSdk == 3) {
                    new_Skin.UAZ = 1908078; //Maserati Levante Firmamento 
                    } else if (UAZSkinHackSdk == 4) {
                    new_Skin.UAZ = 1908076; //Maserati Luce Arancione
                    } else if (UAZSkinHackSdk == 5) {
                    new_Skin.UAZ = 1908075; //Maserati Levante Blu Emozione
                    } else if (UAZSkinHackSdk == 6) {
                    new_Skin.UAZ = 1908067; //Lamborghini Urus Gialla Inti
                    } else if (UAZSkinHackSdk == 7) {
                    new_Skin.UAZ = 1908075; //Maserati Levante Blu Emozione
                    } else if (UAZSkinHackSdk == 8) {
                    new_Skin.UAZ = 1908094; //
                    } else if (UAZSkinHackSdk == 9) {
                    new_Skin.UAZ = 1908095; //
                    } else if (UAZSkinHackSdk == 10) {
                    new_Skin.UAZ = 1957001; //
                    } else if (UAZSkinHackSdk == 11) {
                    new_Skin.UAZ = 1908086; //
                    } else if (UAZSkinHackSdk == 12) {
                    new_Skin.UAZ = 1908066; //
                    } else if (UAZSkinHackSdk == 13) {
                    new_Skin.UAZ = 1908189; //
                    } else if (UAZSkinHackSdk == 14) {
                    new_Skin.UAZ = 1908001; //
                    } 
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

int bag111[] = { 501001, 1501001220, 1501001174, 1501001051, 1501001443, 1501001265, 1501001321, 1501001277, 1501001550, 1501001552, 1501001061};
int bag222[] = { 501002, 1501002220, 1501002174, 1501002051, 1501002443, 1501002265, 1501002321, 1501002277, 1501002550, 1501002552, 1501002061};
int bag333[] = { 501006,501005,501004,501003,501002,501001, 1501003220, 1501003174, 1501003051, 1501003443, 1501003265, 1501003321, 1501003277, 1501003550, 1501003552, 1501003061};



int Helmet1[] = { 502001, 1502001028, 1502001014, 1502001023, 1502001065, 1502001031, 1502001033, 1502001069, 1502001261, 1502001272, 1502001183};
int Helmet2[] = { 502002, 1502002028, 1502002014, 1502002023, 1502002065, 1502002031, 1502002033, 1502002069, 1502002261, 1502002272, 1502002183};
int Helmet3[] = { 502001,502002,502003, 1502003028, 1502003014, 1502003023, 1502003065, 1502003031, 1502003033, 1502003069, 1502003261, 1502003272, 1502003183};


int m4v[] = { 101004, 1101004046, 1101004062, 1101004078, 1101004086, 1101004098, 1101004138, 1101004163,1101004201,1101004209,1101004218};
int scar[] = { 101003, 1101003057, 1101003070, 1101003080, 1101003119, 1101003146, 1101003167, 1101003181};
int akmv[] = { 101001,1101001089, 1101001103, 1101001116, 1101001128, 1101001143, 1101001154, 1101001174,1101001213,1101001231,1101001242};
int m7[] = { 101008, 1101008026, 1101008051, 1101008061, 1101008081, 1101008104, 1101008116, 1101008126};
int awm[] = { 103003, 1103003022, 1103003030, 1103003042, 1103003051, 1103003062};
int amr[] = { 103012, 1103012010};
int mk14[] = { 103007, 1030071, 1030072, 1030073, 1030074, 1030075, 1103007020, 1103007028};
int mg3[] = { 105010, 1105010008};

int kar[] = { 103001, 1103001060, 1103001079, 1103001101, 1103001145, 1103001160, 1103001179};
int m24[] = { 103002, 1103002018, 1103002030, 1103002048, 1103002056, 1103002087};
int dp[] = { 105002, 1105002018, 1105002035, 1105002058, 1105002063};
int m249[] = { 105001, 1105001020, 1105001034, 1105001048, 1105001054};
int groza[] = { 101005, 1101005019, 1101005025, 1101005038, 1101005043, 1101005052, 1101005082};
int aug[] = { 101006, 1101006033, 1101006044, 1101006062};
int m16[] = { 101002, 1101002029, 1101002056, 1101002068, 1101002081, 1101002103};
int uzi[] = { 102001, 1102001024, 1102001036, 1102001058, 1102001069, 1102001089, 1102001102};
int ump[] = { 102002, 1102002043, 1102002061, 1102002090, 1102002117, 1102002124, 1102002129, 1102002136};
int vector2[] = { 102003, 1102003020, 1102003031, 1102003065, 1102003080};
int tommy[] = { 102004, 1102004018, 1102004034};
int bizon[] = { 102005, 1102005007, 1102005020, 1102005041};
int ace32[] = { 101102, 1101102007, 1101102017};
int pan[] = { 108004, 1108004125, 1108004145, 1108004160, 1108004283, 1108004337, 1108004356, 1108004365, 1108004054, 1108004008};

int m249s[] = { 205009, 1050010351, 1050010412, 1050010482, 1050010542};
int akmmag[] = { 291001,204013,204011,204012,1010010891, 1010011031, 1010011161, 1010011281, 1010011431, 1010011541, 1010011741,1010012131,1010012311,1010012421};
int m7mag[] = { 291008,204013,204011,204012,1010080261, 1010080511, 1010080611, 1010080811, 1010081041, 1010081161, 1010081261};
int scarmag[] = { 291003,204013,204011,204012,1010030571, 1010030701, 1010030801, 1010031191, 1010031461, 1010031671, 1010031811};
int m4mag[] = { 291004,204013,204011,204012,1010040461,1010040611,1010040781,1010040861,1010040981,1010041381,1010041631,1010042011,1010042073,1010042153  };

int m4sight[] = { 203008,1010040462,1010040612,1010040782,1010040862,1010040982,1010041382,1010041632,1010042012,1010042083,1010042163  };

int m4stock[] = { 205005,1010040463,1010040613,1010040783,1010040863,1010040983,1010041383,1010041633,1010042013,1010042093,1010042173  };

int m4stock1[] = { 205002,1010040480,205002,205002,205002,205002,1010041146,1010041579,1010041966,1010042137,1010042173  };

int m4reddot[] = { 203001,1010040470,203001,203001,203001,203001,1010041128,1010041566,1010041948,1010042029,1010042119  };

int m16s[] = { 205007, 1010020292, 1010020562, 1010020682, 1010020812, 1010021032};
int m16mag[] = { 291002,204013,204011,204012, 1010020291, 1010020561, 1010020681, 1010020811, 1010021031};

/*
int emote1[] = { 2200101,12220023,12219677,12219716,12209401,12220028,12209701,12209801,12209901 };
int emote2[] = { 2200201,12210201,12210601,12220028,12219819,12211801,12212001,12212201,12212401 };
int emote3[] = { 2200301,12212601,12213201,12219715,12219814,12213601,12213801,12214001,12214201 };
*/
int SuitX[] = { 403003,1405628,1405870,1405983,1406152,1406311,1406475,1406638,1406872 };

int Bag[] = { 501006,501005,501004,501003,501002,501001,1501003550,1501003277,1501003321,1501003443,1501003265,1501003051,1501003220,1501003174 };

int Helmet[] = { 502001,502002,502003,1502003014,1502003028,1502003023,1501002443,1502003031,1502003033,1502003069,1502003261 };


//M416 ONLY
int M4161[] = { 101004, 1101004046, 1101004062, 1101004078, 1101004086, 1101004098, 1101004138, 1101004163, 1101004201, 1101004209, 1101004218};
int M4162[] = { 291004, 1010040461, 1010040611, 1010040781, 1010040861, 1010040981, 1010041381, 1010041631, 1010042011, 1010042073, 1010042153};
int M4163[] = { 203008, 1010040462, 1010040612, 1010040782, 1010040862, 1010040982, 1010041382, 1010041632, 1010042012, 1010042083, 1010042163};
int M4164[] = { 205005, 1010040463, 1010040613, 1010040783, 1010040863, 1010040983, 1010041383, 1010041633, 1010042013, 1010042093, 1010042173};
int M416flash[] = { 201010, 1010040474, 201010, 201010, 201010, 201010, 1010041136, 201010, 1010041956, 20101000, 1010042128};
int M416compe[] = { 201009, 1010040475, 201009, 201009, 201009, 201009, 1010041137, 1010041574, 1010041957, 1010042037, 1010042127};
int M416silent[] = { 201011, 1010040476, 201011, 201011, 201011, 201011, 1010041138, 1010041575, 1010041958, 1010042039, 1010042129};
//int M416reddot[] = { 203001, 1010040470, 203001, 203001, 203001, 203001, 1010041128, 1010041566, 1010041948, 1010042029, 1010042119};
int M416holo[] = { 203002, 1010040469, 203002, 203002, 203002, 203002, 1010041127, 1010041565, 1010041947, 1010042028, 1010042118};
int M416x2[] = { 203003, 1010040468, 203003, 203003, 203003, 203003, 1010041126, 1010041564, 1010041946, 1010042027, 1010042117};
int M416x3[] = { 203014, 1010040467, 203014, 203014, 203014, 203014, 1010041125, 1010041560, 1010041945, 1010042026, 1010042116};
int M416x4[] = { 203004, 1010040466, 203004, 203004, 203004, 203004, 1010041124, 1010041554, 1010041944, 1010042025, 1010042115};
int M416x6[] = { 203015, 1010040481, 203015, 203015, 203015, 203015, 203015, 203015, 1010041967, 1010042024, 1010042114};
int M416quickMag[] = { 204012, 1010040472/*1010040471*/, 204012, 204012, 204012, 204012, 1010041134, 1010041568, 1010041949, 1010042034, 1010042124};
int M416extendedMag[] = { 204011, 1010040473, 204011, 204011, 204011, 204011, 1010041129, 1010041569, 1010041950, 1010042035, 1010042125};
int M416quickNextended[] = { 204013, 1010040473, 204013, 204013, 204013, 204013, 1010041135, 1010041567, 1010041955, 1010042036, 1010042126};
int M416stock[] = { 205002, 1010040480, 205002, 205002, 205002, 205002, 1010041146, 1010041579, 1010041966, 1010042047, 1010042137};
//int M416verical[] = { 203015, 1010040481, 203015, 203015, 203015, 203015, 1010041145, 1010041578, 1010041965, 1010042046, 1010042136};
int M416angle[] = { 202001, 1010040477, 202001, 202001, 202001, 202001, 1010041139, 1010041576, 1010041959, 1010042044, 1010042134};
//int M416lightgrip[] = { 202004, 1010040482, 202004, 202004, 202004, 202004, 202004, 20200400, 202004, 202004, 1010042138};
//int M416pink[] = { 202005, 1010040483, 202005, 202005, 202005, 202005, 202005, 202005, 202005, 202005, 1010042139};
//int M416lazer[] = { 203015, 1010040484, 203015, 203015, 203015, 203015, 203015, 203015, 203015, 203015, 1010042144};
int M416thumb[] = { 202006, 1010040478, 202006, 202006, 202006, 202006, 202006, 1010041577, 202006, 202006, 1010042135};
    
   
    
