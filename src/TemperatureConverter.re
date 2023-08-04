let valueFromEvent = evt => ReactEvent.Form.target(evt)##value;

[@react.component]
let make = () => {
  let (celsius, setCelsius) = React.useState(() => "");
  let (fahrenheit, setFahrenheit) = React.useState(() => "");

  <div>
    <input
      value=celsius
      onChange={evt => {
        let newValue = valueFromEvent(evt);
        setCelsius(_ => newValue);
        switch (float_of_string_opt(newValue)) {
        | None => ()
        | Some(celsius) =>
          let fahrenheit = 9.0 /. 5.0 *. celsius +. 32.0;
          setFahrenheit(_ => string_of_float(fahrenheit));
        };
      }}
    />
    {React.string({js|°C = |js})}
    <input
      value=fahrenheit
      onChange={evt => {
        let newValue = valueFromEvent(evt);
        setFahrenheit(_ => newValue);
        switch (float_of_string_opt(newValue)) {
        | None => ()
        | Some(fahrenheit) =>
          let celsius = (fahrenheit -. 32.) *. 5. /. 9.;
          setCelsius(_ => string_of_float(celsius));
        };
      }}
    />
    {React.string({js|°F|js})}
  </div>;
};
