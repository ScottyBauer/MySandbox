#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>


static unsigned long cache[256];

static unsigned long init_create_mask(char amount, char type)
{
	unsigned long all = type;
	int i;
	for(i=0; i < amount-1; i++){
		all = ((all << 4) | type);
	}
	return all;

}

__attribute__((constructor))
static void cache_init(void)
{
	int i, j;
	unsigned char count = 0;
	for(i = 0; i < 256; i+=16){
		for(j = 0; j < 16; j++){
			cache[i + j] = init_create_mask(j,count);
		}
		count++;
	}
}


void nibble_sort_scotty(unsigned long *buf);

static inline unsigned long create_mask(char amount, char type, char location)
{

	int i;
	unsigned long all = type;
	assert((type * 16)+amount <= 255);
	switch(amount){
	case 0:
		return 0;
	default:
		return cache[ (type * 16) + amount] << location;
	}
}




static inline unsigned long write_new(unsigned long input)
{

	unsigned int where = 64;
	unsigned long write = 0;
	int i;

	for(i = 15; i > 0 && where ; i--){
		where = where - ((input >> (4 * i)) & 0xF)*4;
		write += create_mask((input>>(4 * i) & 0xF), i, where);
	}
	return write;
}





void nibble_sort_scotty(unsigned long *temp)
{
	__builtin_prefetch(temp,1,3);


	unsigned long sorted;
	int i,j;
	int word_holder;
	unsigned long count = 0;
	unsigned char *buf = (unsigned char *)temp;
	for(j = 0; j < 1024; j++){
		for(i = 0; i < 8; i++){
			switch(buf[i]){
		        case 0:
				break;
			case 1:
				count += 0x1;
				break;
			case 2:
				count += 0x10;
				break;
			case 3:
				count += 0x100;
				break;
			case 4:
				count += 0x1000;
				break;
			case 5:
				count += 0x10000;
				break;
			case 6:
				count += 0x100000;
				break;
			case 7:
				count += 0x1000000;
				break;
			case 8:
				count += 0x10000000;
				break;
			case 9:
				count += 0x100000000;
				break;
			case 10:
				count += 0x1000000000;
				break;
			case 11:
				count += 0x10000000000;
				break;
			case 12:
				count += 0x100000000000;
				break;
			case 13:
				count += 0x1000000000000;
				break;
			case 14:
				count += 0x10000000000000;
				break;
			case 15:
				count += 0x100000000000000;
				break;
			case 16:
				count += 0x1;
				break;
			case 17:
				count += 0x2;
				break;
			case 18:
				count += 0x11;
				break;
			case 19:
				count += 0x101;
				break;
			case 20:
				count += 0x1001;
				break;
			case 21:
				count += 0x10001;
				break;
			case 22:
				count += 0x100001;
				break;
			case 23:
				count += 0x1000001;
				break;
			case 24:
				count += 0x10000001;
				break;
			case 25:
				count += 0x100000001;
				break;
			case 26:
				count += 0x1000000001;
				break;
			case 27:
				count += 0x10000000001;
				break;
			case 28:
				count += 0x100000000001;
				break;
			case 29:
				count += 0x1000000000001;
				break;
			case 30:
				count += 0x10000000000001;
				break;
			case 31:
				count += 0x100000000000001;
				break;
			case 32:
				count += 0x10;
				break;
			case 33:
				count += 0x11;
				break;
			case 34:
				count += 0x20;
				break;
			case 35:
				count += 0x110;
				break;
			case 36:
				count += 0x1010;
				break;
			case 37:
				count += 0x10010;
				break;
			case 38:
				count += 0x100010;
				break;
			case 39:
				count += 0x1000010;
				break;
			case 40:
				count += 0x10000010;
				break;
			case 41:
				count += 0x100000010;
				break;
			case 42:
				count += 0x1000000010;
				break;
			case 43:
				count += 0x10000000010;
				break;
			case 44:
				count += 0x100000000010;
				break;
			case 45:
				count += 0x1000000000010;
				break;
			case 46:
				count += 0x10000000000010;
				break;
			case 47:
				count += 0x100000000000010;
				break;
			case 48:
				count += 0x100;
				break;
			case 49:
				count += 0x101;
				break;
			case 50:
				count += 0x110;
				break;
			case 51:
				count += 0x200;
				break;
			case 52:
				count += 0x1100;
				break;
			case 53:
				count += 0x10100;
				break;
			case 54:
				count += 0x100100;
				break;
			case 55:
				count += 0x1000100;
				break;
			case 56:
				count += 0x10000100;
				break;
			case 57:
				count += 0x100000100;
				break;
			case 58:
				count += 0x1000000100;
				break;
			case 59:
				count += 0x10000000100;
				break;
			case 60:
				count += 0x100000000100;
				break;
			case 61:
				count += 0x1000000000100;
				break;
			case 62:
				count += 0x10000000000100;
				break;
			case 63:
				count += 0x100000000000100;
				break;
			case 64:
				count += 0x1000;
				break;
			case 65:
				count += 0x1001;
				break;
			case 66:
				count += 0x1010;
				break;
			case 67:
				count += 0x1100;
				break;
			case 68:
				count += 0x2000;
				break;
			case 69:
				count += 0x11000;
				break;
			case 70:
				count += 0x101000;
				break;
			case 71:
				count += 0x1001000;
				break;
			case 72:
				count += 0x10001000;
				break;
			case 73:
				count += 0x100001000;
				break;
			case 74:
				count += 0x1000001000;
				break;
			case 75:
				count += 0x10000001000;
				break;
			case 76:
				count += 0x100000001000;
				break;
			case 77:
				count += 0x1000000001000;
				break;
			case 78:
				count += 0x10000000001000;
				break;
			case 79:
				count += 0x100000000001000;
				break;
			case 80:
				count += 0x10000;
				break;
			case 81:
				count += 0x10001;
				break;
			case 82:
				count += 0x10010;
				break;
			case 83:
				count += 0x10100;
				break;
			case 84:
				count += 0x11000;
				break;
			case 85:
				count += 0x20000;
				break;
			case 86:
				count += 0x110000;
				break;
			case 87:
				count += 0x1010000;
				break;
			case 88:
				count += 0x10010000;
				break;
			case 89:
				count += 0x100010000;
				break;
			case 90:
				count += 0x1000010000;
				break;
			case 91:
				count += 0x10000010000;
				break;
			case 92:
				count += 0x100000010000;
				break;
			case 93:
				count += 0x1000000010000;
				break;
			case 94:
				count += 0x10000000010000;
				break;
			case 95:
				count += 0x100000000010000;
				break;
			case 96:
				count += 0x100000;
				break;
			case 97:
				count += 0x100001;
				break;
			case 98:
				count += 0x100010;
				break;
			case 99:
				count += 0x100100;
				break;
			case 100:
				count += 0x101000;
				break;
			case 101:
				count += 0x110000;
				break;
			case 102:
				count += 0x200000;
				break;
			case 103:
				count += 0x1100000;
				break;
			case 104:
				count += 0x10100000;
				break;
			case 105:
				count += 0x100100000;
				break;
			case 106:
				count += 0x1000100000;
				break;
			case 107:
				count += 0x10000100000;
				break;
			case 108:
				count += 0x100000100000;
				break;
			case 109:
				count += 0x1000000100000;
				break;
			case 110:
				count += 0x10000000100000;
				break;
			case 111:
				count += 0x100000000100000;
				break;
			case 112:
				count += 0x1000000;
				break;
			case 113:
				count += 0x1000001;
				break;
			case 114:
				count += 0x1000010;
				break;
			case 115:
				count += 0x1000100;
				break;
			case 116:
				count += 0x1001000;
				break;
			case 117:
				count += 0x1010000;
				break;
			case 118:
				count += 0x1100000;
				break;
			case 119:
				count += 0x2000000;
				break;
			case 120:
				count += 0x11000000;
				break;
			case 121:
				count += 0x101000000;
				break;
			case 122:
				count += 0x1001000000;
				break;
			case 123:
				count += 0x10001000000;
				break;
			case 124:
				count += 0x100001000000;
				break;
			case 125:
				count += 0x1000001000000;
				break;
			case 126:
				count += 0x10000001000000;
				break;
			case 127:
				count += 0x100000001000000;
				break;
			case 128:
				count += 0x10000000;
				break;
			case 129:
				count += 0x10000001;
				break;
			case 130:
				count += 0x10000010;
				break;
			case 131:
				count += 0x10000100;
				break;
			case 132:
				count += 0x10001000;
				break;
			case 133:
				count += 0x10010000;
				break;
			case 134:
				count += 0x10100000;
				break;
			case 135:
				count += 0x11000000;
				break;
			case 136:
				count += 0x20000000;
				break;
			case 137:
				count += 0x110000000;
				break;
			case 138:
				count += 0x1010000000;
				break;
			case 139:
				count += 0x10010000000;
				break;
			case 140:
				count += 0x100010000000;
				break;
			case 141:
				count += 0x1000010000000;
				break;
			case 142:
				count += 0x10000010000000;
				break;
			case 143:
				count += 0x100000010000000;
				break;
			case 144:
				count += 0x100000000;
				break;
			case 145:
				count += 0x100000001;
				break;
			case 146:
				count += 0x100000010;
				break;
			case 147:
				count += 0x100000100;
				break;
			case 148:
				count += 0x100001000;
				break;
			case 149:
				count += 0x100010000;
				break;
			case 150:
				count += 0x100100000;
				break;
			case 151:
				count += 0x101000000;
				break;
			case 152:
				count += 0x110000000;
				break;
			case 153:
				count += 0x200000000;
				break;
			case 154:
				count += 0x1100000000;
				break;
			case 155:
				count += 0x10100000000;
				break;
			case 156:
				count += 0x100100000000;
				break;
			case 157:
				count += 0x1000100000000;
				break;
			case 158:
				count += 0x10000100000000;
				break;
			case 159:
				count += 0x100000100000000;
				break;
			case 160:
				count += 0x1000000000;
				break;
			case 161:
				count += 0x1000000001;
				break;
			case 162:
				count += 0x1000000010;
				break;
			case 163:
				count += 0x1000000100;
				break;
			case 164:
				count += 0x1000001000;
				break;
			case 165:
				count += 0x1000010000;
				break;
			case 166:
				count += 0x1000100000;
				break;
			case 167:
				count += 0x1001000000;
				break;
			case 168:
				count += 0x1010000000;
				break;
			case 169:
				count += 0x1100000000;
				break;
			case 170:
				count += 0x2000000000;
				break;
			case 171:
				count += 0x11000000000;
				break;
			case 172:
				count += 0x101000000000;
				break;
			case 173:
				count += 0x1001000000000;
				break;
			case 174:
				count += 0x10001000000000;
				break;
			case 175:
				count += 0x100001000000000;
				break;
			case 176:
				count += 0x10000000000;
				break;
			case 177:
				count += 0x10000000001;
				break;
			case 178:
				count += 0x10000000010;
				break;
			case 179:
				count += 0x10000000100;
				break;
			case 180:
				count += 0x10000001000;
				break;
			case 181:
				count += 0x10000010000;
				break;
			case 182:
				count += 0x10000100000;
				break;
			case 183:
				count += 0x10001000000;
				break;
			case 184:
				count += 0x10010000000;
				break;
			case 185:
				count += 0x10100000000;
				break;
			case 186:
				count += 0x11000000000;
				break;
			case 187:
				count += 0x20000000000;
				break;
			case 188:
				count += 0x110000000000;
				break;
			case 189:
				count += 0x1010000000000;
				break;
			case 190:
				count += 0x10010000000000;
				break;
			case 191:
				count += 0x100010000000000;
				break;
			case 192:
				count += 0x100000000000;
				break;
			case 193:
				count += 0x100000000001;
				break;
			case 194:
				count += 0x100000000010;
				break;
			case 195:
				count += 0x100000000100;
				break;
			case 196:
				count += 0x100000001000;
				break;
			case 197:
				count += 0x100000010000;
				break;
			case 198:
				count += 0x100000100000;
				break;
			case 199:
				count += 0x100001000000;
				break;
			case 200:
				count += 0x100010000000;
				break;
			case 201:
				count += 0x100100000000;
				break;
			case 202:
				count += 0x101000000000;
				break;
			case 203:
				count += 0x110000000000;
				break;
			case 204:
				count += 0x200000000000;
				break;
			case 205:
				count += 0x1100000000000;
				break;
			case 206:
				count += 0x10100000000000;
				break;
			case 207:
				count += 0x100100000000000;
				break;
			case 208:
				count += 0x1000000000000;
				break;
			case 209:
				count += 0x1000000000001;
				break;
			case 210:
				count += 0x1000000000010;
				break;
			case 211:
				count += 0x1000000000100;
				break;
			case 212:
				count += 0x1000000001000;
				break;
			case 213:
				count += 0x1000000010000;
				break;
			case 214:
				count += 0x1000000100000;
				break;
			case 215:
				count += 0x1000001000000;
				break;
			case 216:
				count += 0x1000010000000;
				break;
			case 217:
				count += 0x1000100000000;
				break;
			case 218:
				count += 0x1001000000000;
				break;
			case 219:
				count += 0x1010000000000;
				break;
			case 220:
				count += 0x1100000000000;
				break;
			case 221:
				count += 0x2000000000000;
				break;
			case 222:
				count += 0x11000000000000;
				break;
			case 223:
				count += 0x101000000000000;
				break;
			case 224:
				count += 0x10000000000000;
				break;
			case 225:
				count += 0x10000000000001;
				break;
			case 226:
				count += 0x10000000000010;
				break;
			case 227:
				count += 0x10000000000100;
				break;
			case 228:
				count += 0x10000000001000;
				break;
			case 229:
				count += 0x10000000010000;
				break;
			case 230:
				count += 0x10000000100000;
				break;
			case 231:
				count += 0x10000001000000;
				break;
			case 232:
				count += 0x10000010000000;
				break;
			case 233:
				count += 0x10000100000000;
				break;
			case 234:
				count += 0x10001000000000;
				break;
			case 235:
				count += 0x10010000000000;
				break;
			case 236:
				count += 0x10100000000000;
				break;
			case 237:
				count += 0x11000000000000;
				break;
			case 238:
				count += 0x20000000000000;
				break;
			case 239:
				count += 0x110000000000000;
				break;
			case 240:
				count += 0x100000000000000;
				break;
			case 241:
				count += 0x100000000000001;
				break;
			case 242:
				count += 0x100000000000010;
				break;
			case 243:
				count += 0x100000000000100;
				break;
			case 244:
				count += 0x100000000001000;
				break;
			case 245:
				count += 0x100000000010000;
				break;
			case 246:
				count += 0x100000000100000;
				break;
			case 247:
				count += 0x100000001000000;
				break;
			case 248:
				count += 0x100000010000000;
				break;
			case 249:
				count += 0x100000100000000;
				break;
			case 250:
				count += 0x100001000000000;
				break;
			case 251:
				count += 0x100010000000000;
				break;
			case 252:
				count += 0x100100000000000;
				break;
			case 253:
				count += 0x101000000000000;
				break;
			case 254:
				count += 0x110000000000000;
				break;
			case 255:
				count += 0x200000000000000;
				break;
			default:
				printf("Aborting with buf[i] %u\n",buf[i]);
				__builtin_abort();
			}

		}
		__builtin_prefetch((temp+1),1,3);
		*temp = write_new(count<<4);
		temp++;
		count = 0;
		buf = (unsigned char *)temp;

	}
}


/*
  int main(void)
  {
  //	unsigned long test = 0xc67b1f9a06cac113;
  unsigned long test = 0x728dc8ba40781809;//0xfbbbc9741902c44c;// at 0 to sort to fcccbbb997444210
  nibble_sort_scotty(&test);
  printf("%lx\n", test);

  }


*/
