#pragma once

enum class SceneType
{
	NONE,
	STARTSCENE,
	OPENING,
	PLAYSCENE,
	FEEDBACKSCENE,
	ENDING,
	END,
};

enum class ObjectType
{
	DEFAULT,
	Character,
	STATUS,
	Table,	
	MONEY,
	SCREENFRAME,
	FAME,
	FEE,
	WAITING,
	SCRIPT,
	BUTTON,
	IDCARD,
	YEAR,
	REQUEST,
	NONE,
	END, 
};

enum class EventType
{
	INIT,
	SCENECHANGE,
	CREATEOBJECT,
	DELETEOBJECT,
	PLAYEVENT,
	NONE,
	END,
};

enum class DataObjectType
{
	ADVENTURER,
	QUEST,
	EVENT,

	NONE
};

enum class BrushType
{
	HOLLOW,
	END,
};

enum class PenType
{
	RED,
	GREEN,
	BLUE,
	END
};

enum class PlayEventType
{
	PLAYERWAIT,
	ADVOFF,
	ADVON,
	QUEUECHECK,
	DIALOGUE,
	BUTTINCHECK,
	NONE
};

enum class CharacterName
{
	catfighter1,
	catfighter2,
	dwarf_1,
	dwarf_2,
	herbalist1,
	herbalist2,
	herbalist3,
	herbalist4,
	ninza1,
	ninza2,
	lilian,
	eden,
	darius
};

enum class FeedbackSceneType
{
	MAIN_1,
	MAIN_2,
	MAIN_3,
	EDEN,
	DARIUS,
	LILIAN
};

enum class EndingSceenType
{
	END_1,
	END_2,
	END_3,
	END_4,
	END_5,
	END_6,
	END_DARIUS,
	END_EDEN,
	END_LILIAN
};

enum class RequestRank
{
	BRONZE,
	SILVER,
	GOLD,
	PLATINUM,
	END
};

enum class OpeningSceneType
{
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE
};

enum class ObjectState
{
	OUT_OF_DESK,		// 책상 밖
	ON_THE_DESK,		// 책상 안
	WAS_ON_THE_DESK,	// 책상 '밖'으로 막 나갔다
	WAS_OUT_OF_DESK		// 책상 '안'으로 막 들어왔다
};