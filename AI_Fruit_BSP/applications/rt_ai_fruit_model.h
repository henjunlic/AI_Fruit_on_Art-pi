#ifndef __RT_AI_FRUIT_MODEL_H
#define __RT_AI_FRUIT_MODEL_H

/* model info ... */

// model name
#define RT_AI_FRUIT_MODEL_NAME			"fruit"

#define RT_AI_FRUIT_WORK_BUFFER_BYTES		(23856)

#define AI_FRUIT_DATA_WEIGHTS_SIZE		(648972)

#define RT_AI_FRUIT_BUFFER_ALIGNMENT		(4)

#define RT_AI_FRUIT_IN_NUM				(1)

#define RT_AI_FRUIT_IN_SIZE_BYTES	{	\
	((64 * 64 * 3) * 1),	\
}
#define RT_AI_FRUIT_IN_1_SIZE			(64 * 64 * 3)
#define RT_AI_FRUIT_IN_1_SIZE_BYTES		((64 * 64 * 3) * 1)
#define RT_AI_FRUIT_IN_TOTAL_SIZE_BYTES		((64 * 64 * 3) * 1)



#define RT_AI_FRUIT_OUT_NUM				(1)

#define RT_AI_FRUIT_OUT_SIZE_BYTES	{	\
	((1 * 1 * 7) * 1),	\
}
#define RT_AI_FRUIT_OUT_1_SIZE			(1 * 1 * 7)
#define RT_AI_FRUIT_OUT_1_SIZE_BYTES		((1 * 1 * 7) * 1)
#define RT_AI_FRUIT_OUT_TOTAL_SIZE_BYTES		((1 * 1 * 7) * 1)




#define RT_AI_FRUIT_TOTAL_BUFFER_SIZE		//unused

#endif	//end
