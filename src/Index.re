module App = {
  [@react.component]
  let make = () => <Counter />;
};

let node = ReactDOM.querySelector("#root");
switch (node) {
| Some(root) => ReactDOM.render(<App />, root)
| None => Js.Console.error("Failed to start React: couldn't find the #root element")
};
