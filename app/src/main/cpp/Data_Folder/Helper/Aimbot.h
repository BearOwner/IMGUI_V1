
/*uintptr_t GetTargetByPussy() {
	uintptr_t result = 0;
	float max = std::numeric_limits<float>::infinity();
	auto localPlayer = g_LocalPlayer;
	auto localController = g_LocalController;
	if (localPlayer && localController) {
		auto Actors = getActors();
		for (auto Actor : Actors) {
			if (!isObjectPlayer(Actor))
				continue;
				if (Actor == localPlayer)
				continue;
				if ( * (uint32_t *)(Actor + AUAECharacter_PlayerKey) == * (uint32_t *)(localController + AUAEPlayerController_PlayerKey))
					continue;
				if (*(int *)(Actor + AUAECharacter_TeamID) == * (int *)(localPlayer + AUAECharacter_TeamID))
				     continue;
				if (*(bool *)(Actor + ASTExtraCharacter_bDead))
					continue;
		       if (Config.Aimbot.IgnoreKnocked) {
				if ( * (float *)(Actor + ASTExtraCharacter_Health) == 0.0f)
					continue;
			}
		
			if (Config.Aimbot.IgnoreBots) {
				if ( * (bool *)(Actor + AUAECharacter_bIsAI))
					continue;
			}
				auto RootSc = WorldToScreen(GetBonePos(Actor, 0));
				auto HeadSc = WorldToScreen(GetBonePos(Actor, 1));
					float height = abs(HeadSc.Y - RootSc.Y);
					float width = height * 0.65f;
					Vector3 middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
					if ((middlePoint.X >= 0 && middlePoint.X <= glHeight) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight)) {
						Vector2 v2Middle = Vector2((float)(glHeight / 2), (float)(glHeight / 2));
						Vector2 v2Loc = Vector2(middlePoint.X, middlePoint.Y);
						float dist = Vector2::Distance(v2Middle, v2Loc);
						if (dist < max) {
							max = dist;
							result = Actor;
					
				}
			}
		}
	}
	return result;
}*/
bool isInsideFOV(int x, int y) {
    if (!Config.Aimbot.Cross) 
        return true;

    int circle_x = glWidth / 2;
    int circle_y = glHeight / 2;
    int rad = Config.Aimbot.Cross*0.5f;
    return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}

uintptr_t GetTargetByFov() {
	uintptr_t Target = 0;
	float max = std::numeric_limits<float>::infinity();

    auto localPlayer = g_LocalPlayer;
	auto localController = g_LocalController;
    auto Actors = getActors();
	if (localPlayer && localController) {
		for (auto Actor : Actors) {
			if (!isObjectPlayer(Actor))
				continue;
				if (Actor == localPlayer)
				continue;
				if ( * (uint32_t *)(Actor + AUAECharacter_PlayerKey) == * (uint32_t *)(localController + AUAEPlayerController_PlayerKey))
					continue;
				if (*(int *)(Actor + AUAECharacter_TeamID) == * (int *)(localPlayer + AUAECharacter_TeamID))
				     continue;
				if (*(bool *)(Actor + ASTExtraCharacter_bDead))
					continue;
		       if (Config.Aimbot.IgnoreKnocked) {
				if ( * (float *)(Actor + ASTExtraCharacter_Health) == 0.0f)
					continue;
			}
		
			if (Config.Aimbot.IgnoreBots) {
				if ( * (bool *)(Actor + AUAECharacter_bIsAI))
					continue;
			}
				auto RootSc = WorldToScreen(GetBonePos(Actor, 0));
				auto HeadSc = WorldToScreen(GetBonePos(Actor, 6));
					float height = abs(HeadSc.Y - RootSc.Y);
					float width = height * 0.65f;
					Vector3 middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
					if ((middlePoint.X >= 0 && middlePoint.X <= glHeight) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight)) {
						Vector2 v2Middle = Vector2((float)(glHeight / 2), (float)(glHeight / 2));
						Vector2 v2Loc = Vector2(middlePoint.X, middlePoint.Y);
						if (isInsideFOV((int)middlePoint.X, (int)middlePoint.Y)) {
						float dist = Vector2::Distance(v2Middle, v2Loc);
						if (dist < max) {
							max = dist;
							Target = Actor;
					}
				}
			}
		}
	}
	return Target;
}
