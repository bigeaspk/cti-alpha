_trigger = (_this select 0);

_timer = 0;

while {true} do
	{
		_triggerlist = (list _trigger);
		_blu = blufor countSide list _trigger;
		_red = opfor countSide list _trigger;

		if (_blu > _red) then
		{
			if (_timer < 43) then 
			{
				_timer = (_timer + 1);
			} else
			{
				_timer = _timer;
			}
		};
		if (_red > _blu) then
		{
			if (_timer > 0) then
			{
				_timer = (_timer - 1);
			} else
			{
				_timer = _timer;
			};
		};
		if (_red == _blu) then
		{
			_timer = _timer;
		};
		hint ("Blufor: " + str(_blu) + " Opfor: " + str(_red) + " Timer: " + str(_timer));

		missionNamespace setVariable ["capTimer",_timer];

		sleep 1;
	};