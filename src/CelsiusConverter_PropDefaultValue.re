let getFahrenheit = value =>
  switch (float_of_string_opt(value)) {
  | None when value == "" => {js|? °F|js}
  | None => "error"
  | Some(celsius) =>
    let fahrenheit = 9.0 /. 5.0 *. celsius +. 32.0;
    string_of_float(fahrenheit) ++ {js| °F|js};
  };

[@react.component]
let make = (~value="") => {
  let (celsius, setCelsius) = React.useState(() => value);
  let (fahrenheit, setFahrenheit) = React.useState(() => getFahrenheit(value));

  <div>
    <input
      value=celsius
      onChange={evt => {
        let newValue = ReactEvent.Form.target(evt)##value |> String.trim;
        setCelsius(_ => newValue);
        setFahrenheit(_ => getFahrenheit(newValue));
      }}
    />
    {React.string({js|°C = |js})}
    <span> {React.string(fahrenheit)} </span>
  </div>;
};
