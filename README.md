# GAME_CPP
Thể loại: Bắn súng. 

Ý tưởng: Lấy ý tưởng từ alien shooter, shooter sẽ đi khám phá map và bắn enemy luôn đuổi theo mình
Các chức năng:
+Nhân vật có thể:
  -Di chuyển trái phải lên xuống bằng W-A-S-D
  -Đổi súng
  -Bắn enemy
+Enemy có thể:
  -Luôn đuổi theo nhân vật.
  -Có thể tấn công nhân vật nếu tới đủ gần.
Danh sách file CPP gồm có:
	weapon.cpp: Quản lý vũ khí sử dụng của nhân vật.
	bullet.cpp: Quản lý đạn nhân vật sử dụng, update khi bắn.
	etity.cpp: Định nghĩa chung nhất cho 1 sự vật.
	hero.cpp: Quản lý nhân vật, update vị trí, tình trạng hiện tại (còn sống hay ko,...).
	enemy.cpp: Quản lý enemy, update tình trạng (còn sống không, có tấn công không,...).
	animation.cpp: Update sprite cho các object(quay trái quay phải,...).
