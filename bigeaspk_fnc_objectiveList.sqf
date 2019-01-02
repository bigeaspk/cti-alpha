_allTriggers = allMissionObjects "EmptyDetector";

_objectiveTriggers = [];

{
_string = str(_x) splitString "_";
if ((_string select 0) == "objective") then {
		_objectiveTriggers pushBack str(_x);
	};
} forEach _allTriggers;

hint (_objectiveTriggers joinString " ");