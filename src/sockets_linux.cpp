
class endian_detector
{
public:
	enum	ENDIANNESS{LITTLE,MIXED,BIG,HOST,NETWORK};
private:
	ENDIANNESS	m_eHost_Endianness;
	unsigned char * m_lpcHost_Map_64a[8];
	unsigned char * m_lpcBig_Map_64a[8]; 
	unsigned char * m_lpcLittle_Map_64a[8];
	unsigned char * m_lpcHost_Map_64b[8];
	unsigned char * m_lpcBig_Map_64b[8]; 
	unsigned char * m_lpcLittle_Map_64b[8];
	uint64_t	m_n64a;
	uint64_t	m_n64b;

	unsigned char * m_lpcHost_Map_32a[4];
	unsigned char * m_lpcBig_Map_32a[4]; 
	unsigned char * m_lpcLittle_Map_32a[4];
	unsigned char * m_lpcHost_Map_32b[4];
	unsigned char * m_lpcBig_Map_32b[4]; 
	unsigned char * m_lpcLittle_Map_32b[4];
	uint32_t	m_n32a;
	uint32_t	m_n32b;

	unsigned char * m_lpcHost_Map_16a[2];
	unsigned char * m_lpcBig_Map_16a[2]; 
	unsigned char * m_lpcLittle_Map_16a[2];
	unsigned char * m_lpcHost_Map_16b[2];
	unsigned char * m_lpcBig_Map_16b[2]; 
	unsigned char * m_lpcLittle_Map_16b[2];
	uint32_t	m_n16a;
	uint32_t	m_n16b;

public:
	ENDIANNESS	Get_Endianness(void)const {return m_eHost_Endianness;};
	endian_detector(void)
	{
		uint64_t tVal64 = 0x123456789abcdef0;
		unsigned char * lpPtr64 = (unsigned char *)&tVal64;
		unsigned char * lpInt64a = (unsigned char *)&m_n64a;
		unsigned char * lpInt64b = (unsigned char *)&m_n64b;
		uint32_t tVal32 = 0x12345678;
		unsigned char * lpPtr32 = (unsigned char *)&tVal32;
		unsigned char * lpInt32a = (unsigned char *)&m_n32a;
		unsigned char * lpInt32b = (unsigned char *)&m_n32b;
		uint16_t tVal16 = 0x1234;
		unsigned char * lpPtr16 = (unsigned char *)&tVal16;
		unsigned char * lpInt16a = (unsigned char *)&m_n16a;
		unsigned char * lpInt16b = (unsigned char *)&m_n16b;

		for (unsigned int uiI = 0; uiI < 8; uiI++)
		{
			if (uiI < 2)
			{
				switch (lpPtr16[uiI])
				{
				case 0x12:
					m_lpcHost_Map_16a[uiI] = &(lpInt16a[0]);
					m_lpcHost_Map_16b[uiI] = &(lpInt16b[0]);
					break;
				case 0x34:
					m_lpcHost_Map_16a[uiI] = &(lpInt16a[1]);
					m_lpcHost_Map_16b[uiI] = &(lpInt16b[1]);
					break;
				}
				m_lpcBig_Map_16a[uiI] = &(lpInt16a[uiI]);
				m_lpcBig_Map_16b[uiI] = &(lpInt16b[uiI]);
				m_lpcLittle_Map_16a[uiI] = &(lpInt16a[1 - uiI]);
				m_lpcLittle_Map_16b[uiI] = &(lpInt16b[1 - uiI]);
			}
			if (uiI < 4)
			{
				switch (lpPtr32[uiI])
				{
				case 0x12:
					m_lpcHost_Map_32a[uiI] = &(lpInt32a[0]);
					m_lpcHost_Map_32b[uiI] = &(lpInt32b[0]);
					break;
				case 0x34:
					m_lpcHost_Map_32a[uiI] = &(lpInt32a[1]);
					m_lpcHost_Map_32b[uiI] = &(lpInt32b[1]);
					break;
				case 0x56:
					m_lpcHost_Map_32a[uiI] = &(lpInt32a[2]);
					m_lpcHost_Map_32b[uiI] = &(lpInt32b[2]);
					break;
				case 0x78:
					m_lpcHost_Map_32a[uiI] = &(lpInt32a[3]);
					m_lpcHost_Map_32b[uiI] = &(lpInt32b[3]);
					break;
				}
				m_lpcBig_Map_32a[uiI] = &(lpInt32a[uiI]);
				m_lpcBig_Map_32b[uiI] = &(lpInt32b[uiI]);
				m_lpcLittle_Map_32a[uiI] = &(lpInt32a[3 - uiI]);
				m_lpcLittle_Map_32b[uiI] = &(lpInt32b[3 - uiI]);
			}
			switch (lpPtr64[uiI])
			{
			case 0x12:
				m_lpcHost_Map_64a[uiI] = &(lpInt64a[0]);
				m_lpcHost_Map_64b[uiI] = &(lpInt64b[0]);
				break;
			case 0x34:
				m_lpcHost_Map_64a[uiI] = &(lpInt64a[1]);
				m_lpcHost_Map_64b[uiI] = &(lpInt64b[1]);
				break;
			case 0x56:
				m_lpcHost_Map_64a[uiI] = &(lpInt64a[2]);
				m_lpcHost_Map_64b[uiI] = &(lpInt64b[2]);
				break;
			case 0x78:
				m_lpcHost_Map_64a[uiI] = &(lpInt64a[3]);
				m_lpcHost_Map_64b[uiI] = &(lpInt64b[3]);
				break;
			case 0x9a:
				m_lpcHost_Map_64a[uiI] = &(lpInt64a[4]);
				m_lpcHost_Map_64b[uiI] = &(lpInt64b[4]);
				break;
			case 0xbc:
				m_lpcHost_Map_64a[uiI] = &(lpInt64a[5]);
				m_lpcHost_Map_64b[uiI] = &(lpInt64b[5]);
				break;
			case 0xde:
				m_lpcHost_Map_64a[uiI] = &(lpInt64a[6]);
				m_lpcHost_Map_64b[uiI] = &(lpInt64b[6]);
				break;
			case 0xf0:
				m_lpcHost_Map_64a[uiI] = &(lpInt64a[7]);
				m_lpcHost_Map_64b[uiI] = &(lpInt64b[7]);
				break;
			}
			m_lpcBig_Map_64a[uiI] = &(lpInt64a[uiI]);
			m_lpcBig_Map_64b[uiI] = &(lpInt64b[uiI]);
			m_lpcLittle_Map_64a[uiI] = &(lpInt64a[7 - uiI]);
			m_lpcLittle_Map_64b[uiI] = &(lpInt64b[7 - uiI]);
		}

		if (lpPtr64[0] == 0x12&& lpPtr64[1] == 0x34 && lpPtr64[2] == 0x56 && lpPtr64[3] == 0x78 && lpPtr64[4] == 0x9a && lpPtr64[5] == 0xbc && lpPtr64[6] == 0xde && lpPtr64[7] == 0xf0)
			m_eHost_Endianness = BIG;
		else if (lpPtr64[7] == 0x12&& lpPtr64[6] == 0x34 && lpPtr64[5] == 0x56 && lpPtr64[4] == 0x78 && lpPtr64[3] == 0x9a && lpPtr64[2] == 0xbc && lpPtr64[1] == 0xde && lpPtr64[0] == 0xf0)
			m_eHost_Endianness = LITTLE;
		else
			m_eHost_Endianness = MIXED;

		
	}

	uint64_t Convert_Uint64(ENDIANNESS i_eEndianness_From, ENDIANNESS i_eEndianness_To, uint64_t i_nValue)
	{
		uint64_t tRet;// = i_nValue;
		// from
		if ((i_eEndianness_From == m_eHost_Endianness && i_eEndianness_To == HOST) || // nop
			(i_eEndianness_From == HOST && i_eEndianness_To == m_eHost_Endianness) ||  // nop
			(i_eEndianness_From == HOST && m_eHost_Endianness == BIG && i_eEndianness_To == NETWORK) ||  // nop
			(i_eEndianness_From == NETWORK && i_eEndianness_To == BIG)  || // nop
			(i_eEndianness_From == NETWORK && m_eHost_Endianness == BIG && i_eEndianness_To == HOST) ||  // nop
			(i_eEndianness_From == BIG && i_eEndianness_To == NETWORK)  || // nop
			(i_eEndianness_From == i_eEndianness_To))
		{
			tRet = i_nValue;
		}
		else
		{
			m_n64a = i_nValue;
			switch (i_eEndianness_From)
			{
			case BIG:
			case NETWORK:
				switch (i_eEndianness_To)
				{
				case HOST:
					m_lpcHost_Map_64b[0][0] = m_lpcBig_Map_64a[0][0];
					m_lpcHost_Map_64b[1][0] = m_lpcBig_Map_64a[1][0];
					m_lpcHost_Map_64b[2][0] = m_lpcBig_Map_64a[2][0];
					m_lpcHost_Map_64b[3][0] = m_lpcBig_Map_64a[3][0];
					m_lpcHost_Map_64b[4][0] = m_lpcBig_Map_64a[4][0];
					m_lpcHost_Map_64b[5][0] = m_lpcBig_Map_64a[5][0];
					m_lpcHost_Map_64b[6][0] = m_lpcBig_Map_64a[6][0];
					m_lpcHost_Map_64b[7][0] = m_lpcBig_Map_64a[7][0];
					break;
				case LITTLE:
					m_lpcLittle_Map_64b[0][0] = m_lpcBig_Map_64a[0][0];
					m_lpcLittle_Map_64b[1][0] = m_lpcBig_Map_64a[1][0];
					m_lpcLittle_Map_64b[2][0] = m_lpcBig_Map_64a[2][0];
					m_lpcLittle_Map_64b[3][0] = m_lpcBig_Map_64a[3][0];
					m_lpcLittle_Map_64b[4][0] = m_lpcBig_Map_64a[4][0];
					m_lpcLittle_Map_64b[5][0] = m_lpcBig_Map_64a[5][0];
					m_lpcLittle_Map_64b[6][0] = m_lpcBig_Map_64a[6][0];
					m_lpcLittle_Map_64b[7][0] = m_lpcBig_Map_64a[7][0];
					break;
				case BIG:
				case NETWORK:
				case MIXED:// no definition for mixed.  
					m_n64b = m_n64a;
					break;
				}
				break;
			case LITTLE:
				switch (i_eEndianness_To)
				{
				case HOST:
					m_lpcHost_Map_64b[0][0] = m_lpcLittle_Map_64a[0][0];
					m_lpcHost_Map_64b[1][0] = m_lpcLittle_Map_64a[1][0];
					m_lpcHost_Map_64b[2][0] = m_lpcLittle_Map_64a[2][0];
					m_lpcHost_Map_64b[3][0] = m_lpcLittle_Map_64a[3][0];
					m_lpcHost_Map_64b[4][0] = m_lpcLittle_Map_64a[4][0];
					m_lpcHost_Map_64b[5][0] = m_lpcLittle_Map_64a[5][0];
					m_lpcHost_Map_64b[6][0] = m_lpcLittle_Map_64a[6][0];
					m_lpcHost_Map_64b[7][0] = m_lpcLittle_Map_64a[7][0];
					break;
				case LITTLE:
				case MIXED:
					m_n64b = m_n64a;// no definition for mixed.  
					break;
				case BIG:
				case NETWORK:
					m_lpcBig_Map_64b[0][0] = m_lpcLittle_Map_64a[0][0];
					m_lpcBig_Map_64b[1][0] = m_lpcLittle_Map_64a[1][0];
					m_lpcBig_Map_64b[2][0] = m_lpcLittle_Map_64a[2][0];
					m_lpcBig_Map_64b[3][0] = m_lpcLittle_Map_64a[3][0];
					m_lpcBig_Map_64b[4][0] = m_lpcLittle_Map_64a[4][0];
					m_lpcBig_Map_64b[5][0] = m_lpcLittle_Map_64a[5][0];
					m_lpcBig_Map_64b[6][0] = m_lpcLittle_Map_64a[6][0];
					m_lpcBig_Map_64b[7][0] = m_lpcLittle_Map_64a[7][0];
					break;
				}
				break;
			case MIXED:
				if (m_eHost_Endianness == MIXED)
				{
					switch (i_eEndianness_To)
					{
					case LITTLE:
						m_lpcLittle_Map_64b[0][0] = m_lpcHost_Map_64a[0][0];
						m_lpcLittle_Map_64b[1][0] = m_lpcHost_Map_64a[1][0];
						m_lpcLittle_Map_64b[2][0] = m_lpcHost_Map_64a[2][0];
						m_lpcLittle_Map_64b[3][0] = m_lpcHost_Map_64a[3][0];
						m_lpcLittle_Map_64b[4][0] = m_lpcHost_Map_64a[4][0];
						m_lpcLittle_Map_64b[5][0] = m_lpcHost_Map_64a[5][0];
						m_lpcLittle_Map_64b[6][0] = m_lpcHost_Map_64a[6][0];
						m_lpcLittle_Map_64b[7][0] = m_lpcHost_Map_64a[7][0];
						break;
					case BIG:
					case NETWORK:
						m_lpcBig_Map_64b[0][0] = m_lpcHost_Map_64a[0][0];
						m_lpcBig_Map_64b[1][0] = m_lpcHost_Map_64a[1][0];
						m_lpcBig_Map_64b[2][0] = m_lpcHost_Map_64a[2][0];
						m_lpcBig_Map_64b[3][0] = m_lpcHost_Map_64a[3][0];
						m_lpcBig_Map_64b[4][0] = m_lpcHost_Map_64a[4][0];
						m_lpcBig_Map_64b[5][0] = m_lpcHost_Map_64a[5][0];
						m_lpcBig_Map_64b[6][0] = m_lpcHost_Map_64a[6][0];
						m_lpcBig_Map_64b[7][0] = m_lpcHost_Map_64a[7][0];
						break;
					}
				}
				else
					m_n64b = m_n64a; // no definition for mixed.  
				break;
			case HOST:
				switch (i_eEndianness_To)
				{
				case LITTLE:
					m_lpcLittle_Map_64b[0][0] = m_lpcHost_Map_64a[0][0];
					m_lpcLittle_Map_64b[1][0] = m_lpcHost_Map_64a[1][0];
					m_lpcLittle_Map_64b[2][0] = m_lpcHost_Map_64a[2][0];
					m_lpcLittle_Map_64b[3][0] = m_lpcHost_Map_64a[3][0];
					m_lpcLittle_Map_64b[4][0] = m_lpcHost_Map_64a[4][0];
					m_lpcLittle_Map_64b[5][0] = m_lpcHost_Map_64a[5][0];
					m_lpcLittle_Map_64b[6][0] = m_lpcHost_Map_64a[6][0];
					m_lpcLittle_Map_64b[7][0] = m_lpcHost_Map_64a[7][0];
					break;
				case BIG:
				case NETWORK:
					m_lpcBig_Map_64b[0][0] = m_lpcHost_Map_64a[0][0];
					m_lpcBig_Map_64b[1][0] = m_lpcHost_Map_64a[1][0];
					m_lpcBig_Map_64b[2][0] = m_lpcHost_Map_64a[2][0];
					m_lpcBig_Map_64b[3][0] = m_lpcHost_Map_64a[3][0];
					m_lpcBig_Map_64b[4][0] = m_lpcHost_Map_64a[4][0];
					m_lpcBig_Map_64b[5][0] = m_lpcHost_Map_64a[5][0];
					m_lpcBig_Map_64b[6][0] = m_lpcHost_Map_64a[6][0];
					m_lpcBig_Map_64b[7][0] = m_lpcHost_Map_64a[7][0];
					break;
				case MIXED:
					m_n64b = m_n64a; // no definition for mixed.  
					break;
				}
				break;
			}
			tRet = m_n64b;
		}
		return tRet;
	}
	int64_t Convert_Int64(ENDIANNESS i_eEndianness_From, ENDIANNESS i_eEndianness_To, int64_t i_nValue)
	{
		int64_t tRet;// = i_nValue;
		// from
		if ((i_eEndianness_From == m_eHost_Endianness && i_eEndianness_To == HOST) || // nop
			(i_eEndianness_From == HOST && i_eEndianness_To == m_eHost_Endianness) ||  // nop
			(i_eEndianness_From == HOST && m_eHost_Endianness == BIG && i_eEndianness_To == NETWORK) ||  // nop
			(i_eEndianness_From == NETWORK && i_eEndianness_To == BIG)  || // nop
			(i_eEndianness_From == NETWORK && m_eHost_Endianness == BIG && i_eEndianness_To == HOST) ||  // nop
			(i_eEndianness_From == BIG && i_eEndianness_To == NETWORK)  || // nop
			(i_eEndianness_From == i_eEndianness_To))
		{
			tRet = i_nValue;
		}
		else
			tRet = (int64_t)Convert_Uint64(i_eEndianness_From, i_eEndianness_To, i_nValue);
		return tRet;
	}
	uint32_t Convert_Uint32(ENDIANNESS i_eEndianness_From, ENDIANNESS i_eEndianness_To, uint32_t i_nValue)
	{
		uint32_t tRet;// = i_nValue;
		// from
		if ((i_eEndianness_From == m_eHost_Endianness && i_eEndianness_To == HOST) || // nop
			(i_eEndianness_From == HOST && i_eEndianness_To == m_eHost_Endianness) ||  // nop
			(i_eEndianness_From == HOST && m_eHost_Endianness == BIG && i_eEndianness_To == NETWORK) ||  // nop
			(i_eEndianness_From == NETWORK && i_eEndianness_To == BIG)  || // nop
			(i_eEndianness_From == NETWORK && m_eHost_Endianness == BIG && i_eEndianness_To == HOST) ||  // nop
			(i_eEndianness_From == BIG && i_eEndianness_To == NETWORK)  || // nop
			(i_eEndianness_From == i_eEndianness_To))
		{
			tRet = i_nValue;
		}
		else
		{
			m_n32a = i_nValue;
			switch (i_eEndianness_From)
			{
			case BIG:
			case NETWORK:
				switch (i_eEndianness_To)
				{
				case HOST:
					m_lpcHost_Map_32b[0][0] = m_lpcBig_Map_32a[0][0];
					m_lpcHost_Map_32b[1][0] = m_lpcBig_Map_32a[1][0];
					m_lpcHost_Map_32b[2][0] = m_lpcBig_Map_32a[2][0];
					m_lpcHost_Map_32b[3][0] = m_lpcBig_Map_32a[3][0];
					break;
				case LITTLE:
					m_lpcLittle_Map_32b[0][0] = m_lpcBig_Map_32a[0][0];
					m_lpcLittle_Map_32b[1][0] = m_lpcBig_Map_32a[1][0];
					m_lpcLittle_Map_32b[2][0] = m_lpcBig_Map_32a[2][0];
					m_lpcLittle_Map_32b[3][0] = m_lpcBig_Map_32a[3][0];
					break;
				case BIG:
				case NETWORK:
				case MIXED:// no definition for mixed.  
					m_n32b = m_n32a;
					break;
				}
				break;
			case LITTLE:
				switch (i_eEndianness_To)
				{
				case HOST:
					m_lpcHost_Map_32b[0][0] = m_lpcLittle_Map_32a[0][0];
					m_lpcHost_Map_32b[1][0] = m_lpcLittle_Map_32a[1][0];
					m_lpcHost_Map_32b[2][0] = m_lpcLittle_Map_32a[2][0];
					m_lpcHost_Map_32b[3][0] = m_lpcLittle_Map_32a[3][0];
					break;
				case LITTLE:
				case MIXED:
					m_n32b = m_n32a;// no definition for mixed.  
					break;
				case BIG:
				case NETWORK:
					m_lpcBig_Map_32b[0][0] = m_lpcLittle_Map_32a[0][0];
					m_lpcBig_Map_32b[1][0] = m_lpcLittle_Map_32a[1][0];
					m_lpcBig_Map_32b[2][0] = m_lpcLittle_Map_32a[2][0];
					m_lpcBig_Map_32b[3][0] = m_lpcLittle_Map_32a[3][0];
					break;
				}
				break;
			case MIXED:
				if (m_eHost_Endianness == MIXED)
				{
					switch (i_eEndianness_To)
					{
					case LITTLE:
						m_lpcLittle_Map_32b[0][0] = m_lpcHost_Map_32a[0][0];
						m_lpcLittle_Map_32b[1][0] = m_lpcHost_Map_32a[1][0];
						m_lpcLittle_Map_32b[2][0] = m_lpcHost_Map_32a[2][0];
						m_lpcLittle_Map_32b[3][0] = m_lpcHost_Map_32a[3][0];
						break;
					case BIG:
					case NETWORK:
						m_lpcBig_Map_32b[0][0] = m_lpcHost_Map_32a[0][0];
						m_lpcBig_Map_32b[1][0] = m_lpcHost_Map_32a[1][0];
						m_lpcBig_Map_32b[2][0] = m_lpcHost_Map_32a[2][0];
						m_lpcBig_Map_32b[3][0] = m_lpcHost_Map_32a[3][0];
						break;
					}
				}
				else
					m_n32b = m_n32a; // no definition for mixed.  
				break;
			case HOST:
				switch (i_eEndianness_To)
				{
				case LITTLE:
					m_lpcLittle_Map_32b[0][0] = m_lpcHost_Map_32a[0][0];
					m_lpcLittle_Map_32b[1][0] = m_lpcHost_Map_32a[1][0];
					m_lpcLittle_Map_32b[2][0] = m_lpcHost_Map_32a[2][0];
					m_lpcLittle_Map_32b[3][0] = m_lpcHost_Map_32a[3][0];
					break;
				case BIG:
				case NETWORK:
					m_lpcBig_Map_32b[0][0] = m_lpcHost_Map_32a[0][0];
					m_lpcBig_Map_32b[1][0] = m_lpcHost_Map_32a[1][0];
					m_lpcBig_Map_32b[2][0] = m_lpcHost_Map_32a[2][0];
					m_lpcBig_Map_32b[3][0] = m_lpcHost_Map_32a[3][0];
					break;
				case MIXED:
					m_n32b = m_n32a; // no definition for mixed.  
					break;
				}
				break;
			}
			tRet = m_n32b;
		}
		return tRet;
	}
	int32_t Convert_Int32(ENDIANNESS i_eEndianness_From, ENDIANNESS i_eEndianness_To, int32_t i_nValue)
	{
		int32_t tRet;// = i_nValue;
		// from
		if ((i_eEndianness_From == m_eHost_Endianness && i_eEndianness_To == HOST) || // nop
			(i_eEndianness_From == HOST && i_eEndianness_To == m_eHost_Endianness) ||  // nop
			(i_eEndianness_From == HOST && m_eHost_Endianness == BIG && i_eEndianness_To == NETWORK) ||  // nop
			(i_eEndianness_From == NETWORK && i_eEndianness_To == BIG)  || // nop
			(i_eEndianness_From == NETWORK && m_eHost_Endianness == BIG && i_eEndianness_To == HOST) ||  // nop
			(i_eEndianness_From == BIG && i_eEndianness_To == NETWORK)  || // nop
			(i_eEndianness_From == i_eEndianness_To))
		{
			tRet = i_nValue;
		}
		else
			tRet = (int32_t)Convert_Uint32(i_eEndianness_From, i_eEndianness_To, i_nValue);
		return tRet;
	}
	uint16_t Convert_Uint16(ENDIANNESS i_eEndianness_From, ENDIANNESS i_eEndianness_To, uint16_t i_nValue)
	{
		uint16_t tRet;// = i_nValue;
		// from
		if ((i_eEndianness_From == m_eHost_Endianness && i_eEndianness_To == HOST) || // nop
			(i_eEndianness_From == HOST && i_eEndianness_To == m_eHost_Endianness) ||  // nop
			(i_eEndianness_From == HOST && m_eHost_Endianness == BIG && i_eEndianness_To == NETWORK) ||  // nop
			(i_eEndianness_From == NETWORK && i_eEndianness_To == BIG)  || // nop
			(i_eEndianness_From == NETWORK && m_eHost_Endianness == BIG && i_eEndianness_To == HOST) ||  // nop
			(i_eEndianness_From == BIG && i_eEndianness_To == NETWORK)  || // nop
			(i_eEndianness_From == i_eEndianness_To))
		{
			tRet = i_nValue;
		}
		else
		{
			m_n16a = i_nValue;
			switch (i_eEndianness_From)
			{
			case BIG:
			case NETWORK:
				switch (i_eEndianness_To)
				{
				case HOST:
					m_lpcHost_Map_16b[0][0] = m_lpcBig_Map_16a[0][0];
					m_lpcHost_Map_16b[1][0] = m_lpcBig_Map_16a[1][0];
					break;
				case LITTLE:
					m_lpcLittle_Map_16b[0][0] = m_lpcBig_Map_16a[0][0];
					m_lpcLittle_Map_16b[1][0] = m_lpcBig_Map_16a[1][0];
					break;
				case BIG:
				case NETWORK:
				case MIXED:// no definition for mixed.  
					m_n16b = m_n16a;
					break;
				}
				break;
			case LITTLE:
				switch (i_eEndianness_To)
				{
				case HOST:
					m_lpcHost_Map_16b[0][0] = m_lpcLittle_Map_16a[0][0];
					m_lpcHost_Map_16b[1][0] = m_lpcLittle_Map_16a[1][0];
					break;
				case LITTLE:
				case MIXED:
					m_n16b = m_n16a;// no definition for mixed.  
					break;
				case BIG:
				case NETWORK:
					m_lpcBig_Map_16b[0][0] = m_lpcLittle_Map_16a[0][0];
					m_lpcBig_Map_16b[1][0] = m_lpcLittle_Map_16a[1][0];
					break;
				}
				break;
			case MIXED:
				if (m_eHost_Endianness == MIXED)
				{
					switch (i_eEndianness_To)
					{
					case LITTLE:
						m_lpcLittle_Map_16b[0][0] = m_lpcHost_Map_16a[0][0];
						m_lpcLittle_Map_16b[1][0] = m_lpcHost_Map_16a[1][0];
						break;
					case BIG:
					case NETWORK:
						m_lpcBig_Map_16b[0][0] = m_lpcHost_Map_16a[0][0];
						m_lpcBig_Map_16b[1][0] = m_lpcHost_Map_16a[1][0];
						break;
					}
				}
				else
					m_n16b = m_n16a; // no definition for mixed.  
				break;
			case HOST:
				switch (i_eEndianness_To)
				{
				case LITTLE:
					m_lpcLittle_Map_16b[0][0] = m_lpcHost_Map_16a[0][0];
					m_lpcLittle_Map_16b[1][0] = m_lpcHost_Map_16a[1][0];
					break;
				case BIG:
				case NETWORK:
					m_lpcBig_Map_16b[0][0] = m_lpcHost_Map_16a[0][0];
					m_lpcBig_Map_16b[1][0] = m_lpcHost_Map_16a[1][0];
					break;
				case MIXED:
					m_n16b = m_n16a; // no definition for mixed.  
					break;
				}
				break;
			}
			tRet = m_n16b;
		}
		return tRet;
	}
	int16_t Convert_Int16(ENDIANNESS i_eEndianness_From, ENDIANNESS i_eEndianness_To, int16_t i_nValue)
	{
		int16_t tRet;// = i_nValue;
		// from
		if ((i_eEndianness_From == m_eHost_Endianness && i_eEndianness_To == HOST) || // nop
			(i_eEndianness_From == HOST && i_eEndianness_To == m_eHost_Endianness) ||  // nop
			(i_eEndianness_From == HOST && m_eHost_Endianness == BIG && i_eEndianness_To == NETWORK) ||  // nop
			(i_eEndianness_From == NETWORK && i_eEndianness_To == BIG)  || // nop
			(i_eEndianness_From == NETWORK && m_eHost_Endianness == BIG && i_eEndianness_To == HOST) ||  // nop
			(i_eEndianness_From == BIG && i_eEndianness_To == NETWORK)  || // nop
			(i_eEndianness_From == i_eEndianness_To))
		{
			tRet = i_nValue;
		}
		else
			tRet = (int16_t)Convert_Uint16(i_eEndianness_From, i_eEndianness_To, i_nValue);
		return tRet;
	}
	int Convert_Int(ENDIANNESS i_eEndianness_From, ENDIANNESS i_eEndianness_To, int i_nValue)
	{
		int iRet = i_nValue;
		switch (sizeof(int))
		{
		case 2:
			iRet = (int)Convert_Uint16(i_eEndianness_From, i_eEndianness_To, (uint16_t)i_nValue);
			break;
		case 4:
			iRet = (int)Convert_Uint32(i_eEndianness_From, i_eEndianness_To, (uint32_t)i_nValue);
			break;
		case 8:
			iRet = (int)Convert_Uint64(i_eEndianness_From, i_eEndianness_To, (uint64_t)i_nValue);
			break;
		}
		return iRet;
	}
	unsigned int Convert_Uint(ENDIANNESS i_eEndianness_From, ENDIANNESS i_eEndianness_To, unsigned int i_nValue)
	{
		unsigned int iRet = i_nValue;
		switch (sizeof(int))
		{
		case 2:
			iRet = (unsigned int)Convert_Uint16(i_eEndianness_From, i_eEndianness_To, (uint16_t)i_nValue);
			break;
		case 4:
			iRet = (unsigned int)Convert_Uint32(i_eEndianness_From, i_eEndianness_To, (uint32_t)i_nValue);
			break;
		case 8:
			iRet = (unsigned int)Convert_Uint64(i_eEndianness_From, i_eEndianness_To, (uint64_t)i_nValue);
			break;
		}
		return iRet;
	}
};

char * g_lpcMutli_Data = NULL;
size_t g_zMulti_Data_Size = 0;

size_t Allocate_Multi_Data(const COMMSOCKET::DATATYPES *i_lpeData_Types, unsigned int i_uiNum_Types)
{
	size_t uiTotal_Size = 0;
	for (unsigned int uiI = 0; uiI < i_uiNum_Types; uiI++)
	{
		switch (i_lpeData_Types[uiI])
		{
		case COMMSOCKET::CHAR:
		case COMMSOCKET::UCHAR:
			uiTotal_Size ++;
			break;
		case COMMSOCKET::SHORT:
		case COMMSOCKET::USHORT:
			uiTotal_Size += 2;
			break;
		case COMMSOCKET::INT:
		case COMMSOCKET::UINT:
			uiTotal_Size += 4;
			break;
		case COMMSOCKET::INT64:
		case COMMSOCKET::UINT64:
			uiTotal_Size += 8;
			break;
		case COMMSOCKET::FLOAT:
			uiTotal_Size += 4;
			break;
		case COMMSOCKET::DOUBLE:
			uiTotal_Size += 8;
			break;
		}
	}
	if (uiTotal_Size > g_zMulti_Data_Size)
	{
		if (g_lpcMutli_Data)
			delete [] g_lpcMutli_Data;
		g_lpcMutli_Data = new char[uiTotal_Size];
		g_zMulti_Data_Size = uiTotal_Size;
	}
	return uiTotal_Size;
}
bool COMMSOCKET::Receive_Multi(void * o_lpvData, DATATYPES *i_lpeData_Types, unsigned int i_uiNum_Types)
{
	size_t zSize = Allocate_Multi_Data(i_lpeData_Types, i_uiNum_Types);
	Receive(g_lpcMutli_Data,zSize);
	char * lpResult = (char *)o_lpvData;
	unsigned int uiIdx = 0;
	for (unsigned int uiI = 0; uiI < i_uiNum_Types; uiI++)
	{
		switch (i_lpeData_types[uiI])
		{
		case CHAR:
		case UCHAR:
			lpResult[0] = g_lpcMutli_Data[uiIdx];
			uiIdx++;
			lpResult++;
			break;
		case SHORT:
		case USHORT:
			{
				short * lpShort_Result = (short *)lpResult;
				short * lpShort_Data = (short *)&(g_lpcMutli_Data[uiIdx]);
				lpShort_Result[0] = ntohs(lpShort_Data[0]);
				uiIdx+=2;
				lpResult+=2;
			}
			break;
		case INT:
		case UINT:
			{
				int * lpInt_Result = (int *)lpResult;
				int * lpInt_Data = (int *)&(g_lpcMutli_Data[uiIdx]);
				lpInt_Result[0] = ntohl(lpInt_Data[0]);
				uiIdx+=4;
				lpResult+=4;
			}
			break;
		case INT64:
		case UINT64:
			uiTotal_Size += 8;
			break;
		case FLOAT:
			uiTotal_Size += 4;
			break;
		case DOUBLE:
			uiTotal_Size += 8;
			break;
		}
	}
	
}
bool COMMSOCKET::Send_Multi(void * o_lpvData, DATATYPES *i_lpeData_Types, unsigned int i_uiNum_Types)
{
	size_t zSize = Allocate_Multi_Data(i_lpeData_Types, i_uiNum_Types);
	char * lpResult = (char *)o_lpvData;
	unsigned int uiIdx = 0;
	for (unsigned int uiI = 0; uiI < i_uiNum_Types; uiI++)
	{
		switch (i_lpeData_types[uiI])
		{
		case CHAR:
		case UCHAR:
			lpResult[0] = g_lpcMutli_Data[uiIdx];
			uiIdx++;
			lpResult++;
			break;
		case SHORT:
		case USHORT:
			{
				short * lpShort_Result = (short *)lpResult;
				short * lpShort_Data = (short *)&(g_lpcMutli_Data[uiIdx]);
				lpShort_Data[0] = htons(lpShort_Result[0]);
				uiIdx+=2;
				lpResult+=2;
			}
			break;
		case INT:
		case UINT:
			{
				int * lpInt_Result = (int *)lpResult;
				int * lpInt_Data = (int *)&(g_lpcMutli_Data[uiIdx]);
				lpInt_Data[0] = htonl(lpInt_Result[0]);
				uiIdx+=4;
				lpResult+=4;
			}
			break;
		case INT64:
		case UINT64:
			uiIdx+=8;
			lpResult+=8;
			break;
		case FLOAT:
			uiIdx+=4;
			lpResult+=4;
			break;
		case DOUBLE:
			uiIdx+=8;
			lpResult+=8;
			break;
		}
	}
	Send(g_lpcMutli_Data,zSize);
	
}
