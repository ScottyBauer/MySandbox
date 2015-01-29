#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <emmintrin.h>
#include <smmintrin.h>

/*
  5.8.5 Packed Shuffle Bytes
  PSHUFB Permutes each byte in place, according to
  a shuffle control mask. The least significant three or
  four bits of each shuffle control byte of the control mask form the shuffle index. The shuffle
  mask is unaffected. If the most significant bit
  (bit 7) of a shuffle control byte is set, the
  constant zero is written in the result byte
*/

//typedef unsigned char uchar

//extern const int BUFSIZE;


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
	switch(amount){
	case 0:
		return 0;
	default:
		return cache[ (type * 16) + amount] << location;
	}
}




static inline unsigned long write_new(char ox1, char ox2, char ox3, char ox4,
				      char ox5,char ox6,char ox7,char ox8,
				      char ox9, char oxA,char oxB,char oxC,
				      char oxD,char oxE,char oxF)
{

	unsigned int where = 64;
	unsigned long write = 0;
	
	/* possibly a candidate for obfuscated C contest, remind me to 
	   never create var names like this again 
	*/

	where = where - (oxF * 4);
	write |= create_mask(oxF, 0xF, where);

	where = where - (oxE * 4);
	write |= create_mask(oxE, 0xE, where);

	where = where - (oxD * 4);
	write |= create_mask(oxD, 0xD, where);

	where = where - (oxC * 4);
	write |= create_mask(oxC, 0xC, where);

	where = where - (oxB * 4);
	write |= create_mask(oxB, 0xB, where);

	where = where - (oxA * 4);
	write |= create_mask(oxA, 0xA, where);

	where = where - (ox9 * 4);
	write |= create_mask(ox9, 0x9, where);

	where = where - (ox8 * 4);
	write |= create_mask(ox8, 0x8, where);

	where = where - (ox7 * 4);
	write |= create_mask(ox7, 0x7, where);

	where = where - (ox6 * 4);
	write |= create_mask(ox6, 0x6, where);

	where = where - (ox5 * 4);
	write |= create_mask(ox5, 0x5, where);

	where = where - (ox4 * 4);
	write |= create_mask(ox4, 0x4, where);

	where = where - (ox3 * 4);
	write |= create_mask(ox3, 0x3, where);

	where = where - (ox2 * 4);
	write |= create_mask(ox2, 0x2, where);

	where = where - (ox1 * 4);
	write |= create_mask(ox1, 0x1, where);

	return write;
}





void nibble_sort_scotty(unsigned long *temp)
{
	__builtin_prefetch(temp,1,3);


	unsigned long sorted;
	int i,j;
	int word_holder;
	char ox0 = 0; /* padding */
	char ox1 = 0;
	char ox2 = 0;
	char ox3 = 0;
	char ox4 = 0;
	char ox5 = 0;
	char ox6 = 0;
	char ox7 = 0;
	char ox8 = 0;
	char ox9 = 0;
	char oxA = 0;
	char oxB = 0;
	char oxC = 0;
	char oxD = 0;
	char oxE = 0;
	char oxF = 0;

	unsigned char *buf = (unsigned char *)temp;

	for(j = 0; j < 1024; j++){
		for(i = 0; i < 8; i++){
			switch(buf[i]){
			case 0:
				break;
			case 1:
				ox1++;
				ox0++;
				break;
			case 2:
				ox2++;
				ox0++;
				break;
			case 3:
				ox3++;
				ox0++;
				break;
			case 4:
				ox4++;
				ox0++;
				break;
			case 5:
				ox5++;
				ox0++;
				break;
			case 6:
				ox6++;
				ox0++;
				break;
			case 7:
				ox7++;
				ox0++;
				break;
			case 8:
				ox8++;
				ox0++;
				break;
			case 9:
				ox9++;
				ox0++;
				break;
			case 10:
				oxA++;
				ox0++;
				break;
			case 11:
				oxB++;
				ox0++;
				break;
			case 12:
				oxC++;
				ox0++;
				break;
			case 13:
				oxD++;
				ox0++;
				break;
			case 14:
				oxE++;
				ox0++;
				break;
			case 15:
				oxF++;
				ox0++;
				break;
			case 16:
				ox0++;
				ox1++;
				break;
			case 17:
				ox1++;
				ox1++;
				break;
			case 18:
				ox2++;
				ox1++;
				break;
			case 19:
				ox3++;
				ox1++;
				break;
			case 20:
				ox4++;
				ox1++;
				break;
			case 21:
				ox5++;
				ox1++;
				break;
			case 22:
				ox6++;
				ox1++;
				break;
			case 23:
				ox7++;
				ox1++;
				break;
			case 24:
				ox8++;
				ox1++;
				break;
			case 25:
				ox9++;
				ox1++;
				break;
			case 26:
				oxA++;
				ox1++;
				break;
			case 27:
				oxB++;
				ox1++;
				break;
			case 28:
				oxC++;
				ox1++;
				break;
			case 29:
				oxD++;
				ox1++;
				break;
			case 30:
				oxE++;
				ox1++;
				break;
			case 31:
				oxF++;
				ox1++;
				break;
			case 32:
				ox0++;
				ox2++;
				break;
			case 33:
				ox1++;
				ox2++;
				break;
			case 34:
				ox2++;
				ox2++;
				break;
			case 35:
				ox3++;
				ox2++;
				break;
			case 36:
				ox4++;
				ox2++;
				break;
			case 37:
				ox5++;
				ox2++;
				break;
			case 38:
				ox6++;
				ox2++;
				break;
			case 39:
				ox7++;
				ox2++;
				break;
			case 40:
				ox8++;
				ox2++;
				break;
			case 41:
				ox9++;
				ox2++;
				break;
			case 42:
				oxA++;
				ox2++;
				break;
			case 43:
				oxB++;
				ox2++;
				break;
			case 44:
				oxC++;
				ox2++;
				break;
			case 45:
				oxD++;
				ox2++;
				break;
			case 46:
				oxE++;
				ox2++;
				break;
			case 47:
				oxF++;
				ox2++;
				break;
			case 48:
				ox0++;
				ox3++;
				break;
			case 49:
				ox1++;
				ox3++;
				break;
			case 50:
				ox2++;
				ox3++;
				break;
			case 51:
				ox3++;
				ox3++;
				break;
			case 52:
				ox4++;
				ox3++;
				break;
			case 53:
				ox5++;
				ox3++;
				break;
			case 54:
				ox6++;
				ox3++;
				break;
			case 55:
				ox7++;
				ox3++;
				break;
			case 56:
				ox8++;
				ox3++;
				break;
			case 57:
				ox9++;
				ox3++;
				break;
			case 58:
				oxA++;
				ox3++;
				break;
			case 59:
				oxB++;
				ox3++;
				break;
			case 60:
				oxC++;
				ox3++;
				break;
			case 61:
				oxD++;
				ox3++;
				break;
			case 62:
				oxE++;
				ox3++;
				break;
			case 63:
				oxF++;
				ox3++;
				break;
			case 64:
				ox0++;
				ox4++;
				break;
			case 65:
				ox1++;
				ox4++;
				break;
			case 66:
				ox2++;
				ox4++;
				break;
			case 67:
				ox3++;
				ox4++;
				break;
			case 68:
				ox4++;
				ox4++;
				break;
			case 69:
				ox5++;
				ox4++;
				break;
			case 70:
				ox6++;
				ox4++;
				break;
			case 71:
				ox7++;
				ox4++;
				break;
			case 72:
				ox8++;
				ox4++;
				break;
			case 73:
				ox9++;
				ox4++;
				break;
			case 74:
				oxA++;
				ox4++;
				break;
			case 75:
				oxB++;
				ox4++;
				break;
			case 76:
				oxC++;
				ox4++;
				break;
			case 77:
				oxD++;
				ox4++;
				break;
			case 78:
				oxE++;
				ox4++;
				break;
			case 79:
				oxF++;
				ox4++;
				break;
			case 80:
				ox0++;
				ox5++;
				break;
			case 81:
				ox1++;
				ox5++;
				break;
			case 82:
				ox2++;
				ox5++;
				break;
			case 83:
				ox3++;
				ox5++;
				break;
			case 84:
				ox4++;
				ox5++;
				break;
			case 85:
				ox5++;
				ox5++;
				break;
			case 86:
				ox6++;
				ox5++;
				break;
			case 87:
				ox7++;
				ox5++;
				break;
			case 88:
				ox8++;
				ox5++;
				break;
			case 89:
				ox9++;
				ox5++;
				break;
			case 90:
				oxA++;
				ox5++;
				break;
			case 91:
				oxB++;
				ox5++;
				break;
			case 92:
				oxC++;
				ox5++;
				break;
			case 93:
				oxD++;
				ox5++;
				break;
			case 94:
				oxE++;
				ox5++;
				break;
			case 95:
				oxF++;
				ox5++;
				break;
			case 96:
				ox0++;
				ox6++;
				break;
			case 97:
				ox1++;
				ox6++;
				break;
			case 98:
				ox2++;
				ox6++;
				break;
			case 99:
				ox3++;
				ox6++;
				break;
			case 100:
				ox4++;
				ox6++;
				break;
			case 101:
				ox5++;
				ox6++;
				break;
			case 102:
				ox6++;
				ox6++;
				break;
			case 103:
				ox7++;
				ox6++;
				break;
			case 104:
				ox8++;
				ox6++;
				break;
			case 105:
				ox9++;
				ox6++;
				break;
			case 106:
				oxA++;
				ox6++;
				break;
			case 107:
				oxB++;
				ox6++;
				break;
			case 108:
				oxC++;
				ox6++;
				break;
			case 109:
				oxD++;
				ox6++;
				break;
			case 110:
				oxE++;
				ox6++;
				break;
			case 111:
				oxF++;
				ox6++;
				break;
			case 112:
				ox0++;
				ox7++;
				break;
			case 113:
				ox1++;
				ox7++;
				break;
			case 114:
				ox2++;
				ox7++;
				break;
			case 115:
				ox3++;
				ox7++;
				break;
			case 116:
				ox4++;
				ox7++;
				break;
			case 117:
				ox5++;
				ox7++;
				break;
			case 118:
				ox6++;
				ox7++;
				break;
			case 119:
				ox7++;
				ox7++;
				break;
			case 120:
				ox8++;
				ox7++;
				break;
			case 121:
				ox9++;
				ox7++;
				break;
			case 122:
				oxA++;
				ox7++;
				break;
			case 123:
				oxB++;
				ox7++;
				break;
			case 124:
				oxC++;
				ox7++;
				break;
			case 125:
				oxD++;
				ox7++;
				break;
			case 126:
				oxE++;
				ox7++;
				break;
			case 127:
				oxF++;
				ox7++;
				break;
			case 128:
				ox0++;
				ox8++;
				break;
			case 129:
				ox1++;
				ox8++;
				break;
			case 130:
				ox2++;
				ox8++;
				break;
			case 131:
				ox3++;
				ox8++;
				break;
			case 132:
				ox4++;
				ox8++;
				break;
			case 133:
				ox5++;
				ox8++;
				break;
			case 134:
				ox6++;
				ox8++;
				break;
			case 135:
				ox7++;
				ox8++;
				break;
			case 136:
				ox8++;
				ox8++;
				break;
			case 137:
				ox9++;
				ox8++;
				break;
			case 138:
				oxA++;
				ox8++;
				break;
			case 139:
				oxB++;
				ox8++;
				break;
			case 140:
				oxC++;
				ox8++;
				break;
			case 141:
				oxD++;
				ox8++;
				break;
			case 142:
				oxE++;
				ox8++;
				break;
			case 143:
				oxF++;
				ox8++;
				break;
			case 144:
				ox0++;
				ox9++;
				break;
			case 145:
				ox1++;
				ox9++;
				break;
			case 146:
				ox2++;
				ox9++;
				break;
			case 147:
				ox3++;
				ox9++;
				break;
			case 148:
				ox4++;
				ox9++;
				break;
			case 149:
				ox5++;
				ox9++;
				break;
			case 150:
				ox6++;
				ox9++;
				break;
			case 151:
				ox7++;
				ox9++;
				break;
			case 152:
				ox8++;
				ox9++;
				break;
			case 153:
				ox9++;
				ox9++;
				break;
			case 154:
				oxA++;
				ox9++;
				break;
			case 155:
				oxB++;
				ox9++;
				break;
			case 156:
				oxC++;
				ox9++;
				break;
			case 157:
				oxD++;
				ox9++;
				break;
			case 158:
				oxE++;
				ox9++;
				break;
			case 159:
				oxF++;
				ox9++;
				break;
			case 160:
				ox0++;
				oxA++;
				break;
			case 161:
				ox1++;
				oxA++;
				break;
			case 162:
				ox2++;
				oxA++;
				break;
			case 163:
				ox3++;
				oxA++;
				break;
			case 164:
				ox4++;
				oxA++;
				break;
			case 165:
				ox5++;
				oxA++;
				break;
			case 166:
				ox6++;
				oxA++;
				break;
			case 167:
				ox7++;
				oxA++;
				break;
			case 168:
				ox8++;
				oxA++;
				break;
			case 169:
				ox9++;
				oxA++;
				break;
			case 170:
				oxA++;
				oxA++;
				break;
			case 171:
				oxB++;
				oxA++;
				break;
			case 172:
				oxC++;
				oxA++;
				break;
			case 173:
				oxD++;
				oxA++;
				break;
			case 174:
				oxE++;
				oxA++;
				break;
			case 175:
				oxF++;
				oxA++;
				break;
			case 176:
				ox0++;
				oxB++;
				break;
			case 177:
				ox1++;
				oxB++;
				break;
			case 178:
				ox2++;
				oxB++;
				break;
			case 179:
				ox3++;
				oxB++;
				break;
			case 180:
				ox4++;
				oxB++;
				break;
			case 181:
				ox5++;
				oxB++;
				break;
			case 182:
				ox6++;
				oxB++;
				break;
			case 183:
				ox7++;
				oxB++;
				break;
			case 184:
				ox8++;
				oxB++;
				break;
			case 185:
				ox9++;
				oxB++;
				break;
			case 186:
				oxA++;
				oxB++;
				break;
			case 187:
				oxB++;
				oxB++;
				break;
			case 188:
				oxC++;
				oxB++;
				break;
			case 189:
				oxD++;
				oxB++;
				break;
			case 190:
				oxE++;
				oxB++;
				break;
			case 191:
				oxF++;
				oxB++;
				break;
			case 192:
				ox0++;
				oxC++;
				break;
			case 193:
				ox1++;
				oxC++;
				break;
			case 194:
				ox2++;
				oxC++;
				break;
			case 195:
				ox3++;
				oxC++;
				break;
			case 196:
				ox4++;
				oxC++;
				break;
			case 197:
				ox5++;
				oxC++;
				break;
			case 198:
				ox6++;
				oxC++;
				break;
			case 199:
				ox7++;
				oxC++;
				break;
			case 200:
				ox8++;
				oxC++;
				break;
			case 201:
				ox9++;
				oxC++;
				break;
			case 202:
				oxA++;
				oxC++;
				break;
			case 203:
				oxB++;
				oxC++;
				break;
			case 204:
				oxC++;
				oxC++;
				break;
			case 205:
				oxD++;
				oxC++;
				break;
			case 206:
				oxE++;
				oxC++;
				break;
			case 207:
				oxF++;
				oxC++;
				break;
			case 208:
				ox0++;
				oxD++;
				break;
			case 209:
				ox1++;
				oxD++;
				break;
			case 210:
				ox2++;
				oxD++;
				break;
			case 211:
				ox3++;
				oxD++;
				break;
			case 212:
				ox4++;
				oxD++;
				break;
			case 213:
				ox5++;
				oxD++;
				break;
			case 214:
				ox6++;
				oxD++;
				break;
			case 215:
				ox7++;
				oxD++;
				break;
			case 216:
				ox8++;
				oxD++;
				break;
			case 217:
				ox9++;
				oxD++;
				break;
			case 218:
				oxA++;
				oxD++;
				break;
			case 219:
				oxB++;
				oxD++;
				break;
			case 220:
				oxC++;
				oxD++;
				break;
			case 221:
				oxD++;
				oxD++;
				break;
			case 222:
				oxE++;
				oxD++;
				break;
			case 223:
				oxF++;
				oxD++;
				break;
			case 224:
				ox0++;
				oxE++;
				break;
			case 225:
				ox1++;
				oxE++;
				break;
			case 226:
				ox2++;
				oxE++;
				break;
			case 227:
				ox3++;
				oxE++;
				break;
			case 228:
				ox4++;
				oxE++;
				break;
			case 229:
				ox5++;
				oxE++;
				break;
			case 230:
				ox6++;
				oxE++;
				break;
			case 231:
				ox7++;
				oxE++;
				break;
			case 232:
				ox8++;
				oxE++;
				break;
			case 233:
				ox9++;
				oxE++;
				break;
			case 234:
				oxA++;
				oxE++;
				break;
			case 235:
				oxB++;
				oxE++;
				break;
			case 236:
				oxC++;
				oxE++;
				break;
			case 237:
				oxD++;
				oxE++;
				break;
			case 238:
				oxE++;
				oxE++;
				break;
			case 239:
				oxF++;
				oxE++;
				break;
			case 240:
				ox0++;
				oxF++;
				break;
			case 241:
				ox1++;
				oxF++;
				break;
			case 242:
				ox2++;
				oxF++;
				break;
			case 243:
				ox3++;
				oxF++;
				break;
			case 244:
				ox4++;
				oxF++;
				break;
			case 245:
				ox5++;
				oxF++;
				break;
			case 246:
				ox6++;
				oxF++;
				break;
			case 247:
				ox7++;
				oxF++;
				break;
			case 248:
				ox8++;
				oxF++;
				break;
			case 249:
				ox9++;
				oxF++;
				break;
			case 250:
				oxA++;
				oxF++;
				break;
			case 251:
				oxB++;
				oxF++;
				break;
			case 252:
				oxC++;
				oxF++;
				break;
			case 253:
				oxD++;
				oxF++;
				break;
			case 254:
				oxE++;
				oxF++;
				break;
			case 255:
				oxF+=2;
				break;
			default:
				__builtin_abort();
			}
		}
		__builtin_prefetch((temp+1),1,3);
		*temp = write_new(ox1,ox2,ox3,ox4,ox5,ox6,ox7,ox8,
				  ox9,oxA,oxB,oxC,oxD,oxE,oxF);
		ox1 = 0;
		ox2 = 0;
		ox3 = 0;
		ox4 = 0;
		ox5 = 0;
		ox6 = 0;
		ox7 = 0;
		ox8 = 0;
		ox9 = 0;
		oxA = 0;
		oxB = 0;
		oxC = 0;
		oxD = 0;
		oxE = 0;
		oxF = 0;
		temp++;
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
