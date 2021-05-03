# Flappy-Bird
Game Flappy Bird:
- Cách chơi: click vào màn hình để đẩy con chim bay cao sao cho k chạm vào cột
- cách thành phần cơ bản trong game:
	+ con chim
	+ cột
	+ ống	
	+ phông nền và mặt đất
	+ màn hình menu
 	+ màn hình game over
	+ bảng điểm
- vai trò của các chương trình con trong game:
	+ sound: dùng để gọi file âm thanh wav
	+ main: dùng để chạy toàn bộ project và vòng lặp game
	+game object: lưu trữ các chi tiết của đối tượng trong game. ví dụ như: vị trí, kích thước, và cập nhật vị trí theo thời gian chơi...
	+ bird: lưu trữ các thông tin cơ bản của con chim: cách vẫy cánh, cúi xuống khi rơi, ...
	+ texture manager: dùng để load texture
	+ function: dùng để chứa các hàm con như : point, click, collision...
- sử dụng thư viện đồ họa, âm thanh và hình ảnh của sdl2

	
