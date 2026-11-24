import struct
for h in (0x41680000, 0x41700000, 0x41600000, 0x41500000):
    print("0x%08X = %.6f" % (h, struct.unpack("<f", struct.pack("<I", h))[0]))
print("14.5 ->", "0x%08X" % struct.unpack("<I", struct.pack("<f", 14.5))[0])
print("15.0 ->", "0x%08X" % struct.unpack("<I", struct.pack("<f", 15.0))[0])
print("level15 = 7.0+0.5*15 =", 7.0 + 0.5 * 15)
print("level16 = 7.0+0.5*16 =", 7.0 + 0.5 * 16)
print("0x41680000 -> level by 7+0.5L:", (struct.unpack("<f", struct.pack("<I", 0x41680000))[0] - 7.0) / 0.5)
import math
print("сдвиг экрана: 0.5*sin(0.29) =", 0.5 * math.sin(0.29), "клетки")
print("перекрытие: (14.5-12.5)*tan(0.29) =", (14.5 - 12.5) * math.tan(0.29), "рядов")
print("дно породы: (14.5-7.0)*tan(0.29) =", (14.5 - 7.0) * math.tan(0.29), "рядов")
print("DeltaZ=3.5: sin ->", 3.5 * math.sin(0.29), " tan ->", 3.5 * math.tan(0.29))
