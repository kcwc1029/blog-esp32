import sys
from bdfparser import Font

text_file = 'fonts.txt'     # 文字內容
output_file = 'fonts.h'     # 輸出檔名
font = Font('bdf\\fusion-pixel.bdf')  # 像素字體檔

def getArray(chr):
    hex_list = []
    glyph = font.glyph(chr)
    hexdata = glyph.meta['hexdata']
    num_list =  [int(hex_str, 16) for hex_str in hexdata]

    for col in range(13):
        num = 0
        row = 0
        while row < len(num_list):
            digit = (num_list[row] >> (15-col)) & 1
            num = ((digit << row) | num)
            row += 1
            
        hex_list.append(num)

    if ord(chr) > 255:
        _list = hex_list[:-2]
        return [len(_list)] + _list
    else:
        _list = hex_list[8:]
        return [len(_list)] + _list

def main():
    txt = ''
    output_header = 'const uint16_t fonts[][12] PROGMEM = {\n'

    try:
        # 讀取fonts.txt裡的文字
        with open(text_file, encoding='utf-8') as file:
            txt = file.read().replace('\n', '').replace('\r', '')

    except FileNotFoundError:
        print(f"出錯囉～找不到 {text_file} 檔。")
        sys.exit()  # 關閉程式

    for chr in txt:
        decimal_list = getArray(chr)
        result_list = [str(decimal_list[0])]
        result_list.extend([f'0x{num:X}' for num in decimal_list[1:]])
        formatted_string = '{ ' + ', '.join(result_list) + ' }, // ' + chr + '\n'
        output_header += formatted_string 

    output_header += '};'

    # 產生C語言標頭檔
    with open(output_file, 'w') as f:
        f.write(output_header)

if __name__ == '__main__':
    main()
