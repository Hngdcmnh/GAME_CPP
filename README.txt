# GAME_CPP
Thể loại: Bắn súng. 

Ý tưởng: Lấy ý tưởng từ alien shooter, shooter sẽ đi khám phá map và bắn enemy luôn đuổi theo mình
Các chức năng:
+Nhân vật có thể:
  -Di chuyển trái phải lên xuống bằng W-A-S-D
  -Đổi súng
  -Bắn enemy
  -Ném lựu đạn
+Enemy có thể:
  -Luôn đuổi theo nhân vật.
  -Có thể tấn công nhân vật nếu tới đủ gần.
Danh sách file gồm có:
-	lib.h: Thư viện chung có chứa các thư viện iostream, SFML/Graphics.hpp,…
-	animation: Thực hiện animation cho đối tượng.
-	state: Định nghĩa chung 1 state.
-	state_menu: Menu có các button Play, Exit, Info.
-	state_game: Thực hiện game, tạo enemy, nhận các thao tác từ bàn phím, xử lý va chạm, update đối tượng, in ra màn hình,…
-	state_end: Màn hình kết thúc game.
-	entity: Định nghĩa chung nhất cho 1 đối tượng.
-	hero: Định nghĩa nhân vật, update các trạng thái (di chuyển , đứng yên ), thực hiện move left right up down, tăng giảm máu,…
-	energy_bar: Thanh năng lượng (sẽ tăng lên khi bắn enemy bằng súng, khi đầy có thể gọi tank).
-	enemy: Định nghĩa enemy, update các trạng thái cho enemy (di chuyển, tấn công, mất máu, die,... ).
-	add_blood: trái tim tăng máu cho hero khi ăn.
-	weapon: Định nghĩa các vũ khí của hero.
-	bullet: Định nghĩa đạn của hero.
-	collide: xử lí va chạm của đạn với enemy.
-	nade: lựu đạn cho hero.

