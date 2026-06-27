#include <raylib.h>
Color color887 = {136, 126, 224, 255};
#define MAX_BUILDINGS 100
class Game {
public:
  const int width = 800;
  const int height = 450;
  Rectangle player = {400, 280, 40, 40};
  Rectangle buildings[MAX_BUILDINGS] = {0};
  Color buildcolor[MAX_BUILDINGS] = {0};
  int spacing = 0;
  float velocity = 0.0f;
  float gravity = 0.8f;
  bool ground = true;
  const float groundleft = -6200;
  const float groundright = -6200 + 13000;
  void InitBuilding() {
    for (int i = 0; i < MAX_BUILDINGS; i++) {
      buildings[i].width = (float)GetRandomValue(50, 200);
      buildings[i].height = (float)GetRandomValue(100, 800);
      buildings[i].y = height - 130.0f - buildings[i].height;
      buildings[i].x = -6000.0f + spacing;
      spacing += (int)buildings[i].width;

      buildcolor[i] = (Color){(unsigned char)GetRandomValue(160, 200),
                              (unsigned char)GetRandomValue(160, 200),
                              (unsigned char)GetRandomValue(150, 200), 255};
    }
  }

 void UpdatePlayer() {
    if (IsKeyDown(KEY_D)) {
      player.x += 20.0f;

    } else if (IsKeyDown(KEY_A)) {

      player.x -= 20.0f;
    }
    if (IsKeyPressed(KEY_W) && ground == true) {
      velocity = -14.0f;
      ground = false;
    }
    if (!ground) {
      velocity += gravity;
      player.y += velocity;
    }
    if (player.y > 280) {
      player.y = 280;
      velocity = 0;
      ground = true;
    }
 }

 
  void DrawBuilding() {
    for (int i = 0; i < MAX_BUILDINGS; i++) {
      DrawRectangleRec(buildings[i], buildcolor[i]);
    }
  }
  void Drawground() { DrawRectangle(-6200, 320, 13000, 8000, DARKGRAY); }
  void DrawPlayer() { DrawRectangleRec(player, color887); }
};
int main() {
  Game game;
  InitWindow(game.width, game.height, "CAMERA");
  game.InitBuilding();
  Camera2D camera = {0};
  camera.target = (Vector2){game.player.x + game.player.width / 2,
                            game.player.y + game.player.height / 2};
  camera.offset = (Vector2){game.width / 2.0f, game.height / 2.0f};
  camera.rotation = 0.0f;

  camera.zoom = 0.0f;
  SetTargetFPS(60);

  while (!WindowShouldClose()) {

    game.UpdatePlayer();
    camera.target = (Vector2){game.player.x + game.player.width,
                              game.player.y + game.player.height};
    camera.zoom += GetMouseWheelMove() * 0.1;
    BeginDrawing();
    BeginMode2D(camera);
    ClearBackground(RAYWHITE);
    game.Drawground();
    game.DrawBuilding();
    game.DrawPlayer();
    EndMode2D();
    EndDrawing();
  }
  CloseWindow();
}
